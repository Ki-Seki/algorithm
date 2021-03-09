#include <iostream>
#include <cstring>
#define MAXN 80  // 组合数表的最大尺度
typedef long long LL;
using namespace std;

// <<<<<<部分辅助函数>>>>>>

LL primes[MAXN], primes_cnt = 0;
bool not_prime[MAXN] = {};
// 找到 n 以内的素数
void find_prime(LL n)
{
    for (int i = 2; i <= n; i++)
        if (not_prime[i] == 0)
        {
            primes[primes_cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                not_prime[j] = true;
        }
}

// 快速幂计算 a^b%c
LL fastPower(LL a, LL b, LL c)
{
    LL ans = 1;
    a %= c;  // 优化
    while (b)
    {
        if (b & 1) ans = ans * a % c;
        a *= a;
        b >>= 1;
    }
    return ans;
}

// 扩展欧几里得算法
LL exGcd(LL a, LL b, LL& x, LL& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        LL gcd = exGcd(b, a%b, x, y),
            tmp = x;
        x = y;
        y = tmp - (a / b) * y;
        return gcd;
    }
}

// 逆元求解，即求解 ax ≡ 1(mod b)
LL inverse(LL a, LL b)
{
    LL x, y, interval = b / exGcd(a, b, x, y);
    return ((x % interval) + interval) % interval;
}

// <<<<<<问题 1：计算 prime counts in a factorial，即 n! 中有多少个质因子 p>>>>>>

int pcf_recursion(int n, int p)
{
    if (n >= p) return n / p + pcf_recursion(n / p, p);
    else return 0;
}
int pcf_iteration(int n, int p)
{
    int cnt = 0;
    while (n)
    {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

LL cbn[MAXN][MAXN] = {};  // 组合数计算记忆优化所用到的表

// <<<<<<问题 2：组合数 C_n^m 的计算>>>>>>

// 递归 + 记忆优化
LL cbn_recursion(LL n, LL m)
{
    if (m == 0 || n == m) return 1;
    else if (cbn[n][m] != 0) return cbn[n][m];
    else return cbn[n][m] = cbn_recursion(n - 1, m - 1) + cbn_recursion(n - 1, m);
}
// 递推 + 记忆优化
LL cbn_iteration(LL n, LL m)
{
    // 初始化边界值
    for (int i = 1; i <= n; i++)
        cbn[i][0] = cbn[i][i] = 1;
    // 递推计算
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i / 2; j++)
        {
            cbn[i][j] = cbn[i-1][j-1] + cbn[i-1][j];
            cbn[i][i - j] = cbn[i][j];  // 优化
        }
    return cbn[n][m];
}
// 定义式分解，时间复杂度：O(n)
LL cbn_defination(LL n, LL m)
{
    LL ans = 1;
    for (LL i = 1; i <= m; i++)
        ans = ans * (n - m + i) / i;  // 必须先乘后除
        // 不能写成：“ans *= (n - m + i) / i;” ≡ “ans = ans *((n - m + i) / i);”
    return ans;
}

// <<<<<<问题 3：C_n^m % p 的计算>>>>>>

// 递归 + 记忆优化
LL cbn_recursion(LL n, LL m, LL p)
{
    if (m == 0 || n == m) return 1;
    if (cbn[n][m] != 0) return cbn[n][m];
    return cbn[n][m] = (cbn_recursion(n - 1, m) + cbn_recursion(n - 1, m - 1)) % p;
}
// 递推 + 记忆优化
LL cbn_iteration(LL n, LL m, LL p)
{
    for (int i = 0; i <= n; i++)
        cbn[i][0] = cbn[i][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i / 2; j++)
        {
            cbn[i][j] = (cbn[i-1][j-1] + cbn[i-1][j]) % p;
            cbn[i][i - j] = cbn[i][j];  // 优化
        }
    return cbn[n][m];
}
// 定义式 + 阶乘的质因子分解
LL cbn_defination(LL n, LL m, LL p)
{
    LL ans = 1;
    find_prime(n);
    for (int i = 0; i < primes_cnt; i++)
    {
        // 找到 cbn 中质因子 primes[i] 的个数 p_cnt
        LL p_cnt = pcf_recursion(n, primes[i]) - pcf_recursion(m, primes[i]) - pcf_recursion(n - m, primes[i]);
        // 快速幂计算 primes[i] ^ p_cnt % p
        ans = (ans * fastPower(primes[i], p_cnt, p)) % p;
    }
    return ans;
}
// 特殊情况 1（m < p, p 是素数）：利用逆元求解
LL cbn_inverse(LL n, LL m, LL p)
{
    LL ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * (n - m + i) % p * inverse(i, p) % p;
    return ans;
}
// 特殊情况 2（m 任意，p 是素数）：去除多余素数 p + 逆元求解

// 特殊情况 3（m，p 均任意）：

// Lucas 定理

int main()
{
    cout << pcf_recursion(10, 2) << ' ' << pcf_iteration(10, 2)  << endl
         << cbn_recursion(40, 20) << ' ' << cbn_iteration(40, 20) << ' ' << cbn_defination(40, 20) << endl;
    memset(cbn, 0, sizeof(cbn));
    cout << cbn_recursion(40, 20, 71) << ' ' << cbn_iteration(40, 20, 71) << ' ';
    memset(cbn, 0, sizeof(cbn));
    cout << cbn_defination(40, 20, 71) << ' ' << cbn_inverse(40, 20, 71);
    return 0;
}