#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

/* 
保存高精度的非负整数，提供其加减乘除及比较运算
若原数字是 1234567890，则 s = {34567890, 12} 
*/
struct BigInteger
{
    static const int BASE = 100000000;  // 基数
    static const int WIDTH = 8;  // 数组 s 中每个元素的位数
    vector<int> s;  // 保存大整数的整数

    // construction
    BigInteger(long long num = 0) { *this = num; }

    // assignment
    BigInteger operator = (long long num)
    {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger operator = (const string& str)
    {
        s.clear();
        int x;  // 临时变量
        int len = (str.length() - 1) / WIDTH + 1;  // 四舍五入，实现将 str 按 WIDTH 分段
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);  // c_str 将 string 转换为 c 字符串
            s.push_back(x);
        }
        return *this;
    }

    // arithmetic

    // 低位到高位，分段求解，记录进位
    BigInteger operator + (const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();

        // i：同时遍历保存两个大整数的数组
        // g：记录进位的值
        for (int i = 0, g = 0; ; i++)
        {
            // 循环终止条件：大整数们都已遍历完，且无进位 
            if (g == 0 && i >= s.size() && i >= b.s.size())
                break;
            
            // 计算第 i 段的和 x，x 最大不超过 3 * 10^8 ，因此可用 int 保存
            int x = g;  // 加上进位
            if (i < s.size()) x += s[i];  // 加上第一个加数
            if (i < b.s.size()) x += b.s[i];  // 加上第二个加数

            c.s.push_back(x % BASE);  // 结果保存到 c
            g = x / BASE;  // 计算进位
        }
        return c;
    }
    
    // 标准化处理，然后低位到高位，分段求解，记录进位
    BigInteger operator - (const BigInteger& b) const
    {
        BigInteger d, e;  // 被减数和减数
        BigInteger diff;  // 差值
        int sign = 1;
        diff.s.clear();

        // 计算符号，获得被减数和减数
        if (*this < b)
        {
            d = b;
            e = *this;
            sign = -1;
        }
        else if (b < *this)
        {
            d = *this;
            e = b;
            sign = 1;
        }
        else
        {
            diff = 0;
            return diff;
        }
        
        // i：遍历被减数数组
        // g：借位
        // 从低位开始，依次对应地由被减数数组减去减数数组
        for (int i = 0, g = 0; i < d.s.size(); i++)
        {
            if (i < e.s.size())  // 未超出 减数 向量段数
            {
                if (d.s[i] < e.s[i])  // 需要借位
                {
                    int tmp = (d.s[i] - g) + BASE - e.s[i];
                    //当且仅当目前在最高位段，且借位后差为 0 时，才不再 push
                    if (tmp != 0 || i != d.s.size() - 1)
                        diff.s.push_back(tmp);
                    g = 1;  // 借位
                }
                else if (d.s[i] > e.s[i])  // 无需借位
                {
                    int tmp = (d.s[i] - g) - e.s[i];
                    if (tmp != 0 || i != d.s.size() - 1)
                        diff.s.push_back(tmp);
                    g = 0;
                }
                else  // 第 i 段完全相同
                {
                    if (g == 0)  // 之前的借位为 0 
                    {
                        if (i != d.s.size() - 1)
                            diff.s.push_back(0);
                        g = 0;
                    }
                    else  // 之前的借位传递导致此次也需要借位
                    {
                        int tmp = BASE - g;
                        if (tmp != 0 || i != d.s.size() - 1)
                            diff.s.push_back(tmp);
                        g = 1;
                    }
                    
                }
                
            }
            else  // 超出 减数 向量段数
            {
                int temp = d.s[i] - g;
                if (temp != 0 || i != d.s.size() - 1)
                    diff.s.push_back(temp);
                g = 0;
            }
        }
        diff.s[diff.s.size() - 1] *= sign;  // 符号化，diff 之后可能不能继续参与 BigInteger 类型的计算
        return diff;
    }
    
    // 竖式乘法模拟求解，也可以变乘法为加法求解
    BigInteger operator * (const BigInteger& b) const
    {
        BigInteger product;
        // 出于性能考虑，以下两变量不在循环体内定义
        BigInteger section_prod;
        long long tmp;
        for (int i = 0; i < b.s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                section_prod.s.clear();
                tmp = (long long) b.s[i] * s[j];  // tmp 位数小于 16
                for (int k = 0; k < i + j; k++)
                    section_prod.s.push_back(0);  // 竖式乘法的错位
                do{
                    section_prod.s.push_back(tmp % BASE);
                    tmp /= BASE;
                } while (tmp > 0);  // 最多循环两次
                product += section_prod;
            }
        }
        return product;
    }

    // 多次减法实现除法，通过被除数除数左对齐进行简单优化
    BigInteger operator / (const BigInteger& b) const
    {
        BigInteger quotient, remainder;
        quotient.s.clear();
        remainder.s.clear();
        if (b == 0)
        {
            cout << "error: divizor can't be 0." << endl;
            exit(1);
        }
        else if (b == 1)
        {
            quotient = *this;
            remainder = 0;
        }
        else if (*this == 0)
        {
            quotient = 0;
            remainder = 0;
        }
        else if (*this == b)
        {
            quotient = 1;
            remainder = 0;
        }
        else if (*this < b)
        {
            quotient = 0;
            remainder = *this;
        }
        else  // 除上述特殊情况的，被除数大于除数的情况
        {
            quotient = 0;
            /* TODO */
        }
        return quotient;
    }

    // syntactic sugar
    BigInteger operator += (const BigInteger& b) { *this = *this + b; return *this; }
    BigInteger operator -= (const BigInteger& b) { *this = *this - b; return *this; }
    BigInteger operator *= (const BigInteger& b) { *this = *this * b; return *this; }
    BigInteger operator /= (const BigInteger& b) { *this = *this / b; return *this; }

    // comparison
    bool operator < (const BigInteger& b) const
    {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;  // 仅当大于等于时返回 false
    }
    bool operator > (const BigInteger& b) const { return b < *this; }
    bool operator <= (const BigInteger& b) const { return !(b < *this); }
    bool operator >= (const BigInteger& b) const { return !(*this < b); }
    bool operator != (const BigInteger& b) const { return b < *this || *this < b; }
    bool operator == (const BigInteger& b) const { return !(b < *this) && !(*this < b); }

};

// syntactic sugar
ostream& operator << (ostream& out, const BigInteger& x)
    {
        out << x.s.back();  // 先将有可能不满足 8 位的数组末尾元素输出，方便下面的 for 循环
        for (int i = x.s.size() - 2; i >= 0; i--)  // 遍历大整数的每一段
        {
            char buf[20];
            // sprintf(buf, "%08d", x.s[i]);  // 8 位长度，不够补 0
            // for (int j = 0; j < strlen(buf); j++)
            //     out << buf[j];
            cout << x.s[i];  // 以上三行代码按理说应该与此行代码等价
        }
        return out;
    }
istream& operator >> (istream& in, BigInteger& x)
{
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

int main()
{
    BigInteger a, b = 5;
    a = string("90");
    BigInteger c;
    c = "10000000";
    cout << b / 0 << endl << a.s[0];
    return 0;
}