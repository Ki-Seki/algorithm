- [选择排序 Select Sort](#选择排序-select-sort)
- [插入排序 Insertion Sort](#插入排序-insertion-sort)
- [全排列 Full Permutation](#全排列-full-permutation)
- [二分查找 Binary Search](#二分查找-binary-search)
- [快速幂 Fast Power](#快速幂-fast-power)
- [](#)
- [](#-1)
- [](#-2)

# 选择排序 Select Sort

hint:

1. `* 运算符：定义变量时指示变量为指针；解引用运算符，即取地址对应的值`

2. `& 运算符：取地址运算符；按位与运算符`

code:

```c++
void sort(int *start, int *end)
{
    for (int i = 0; start + i < end; i++)  // 从 start + i 到 end 是 待排部分
    {
        int min = i;
        for (int j = i + 1; start + j < end; j++)  // 找到最小值下标
            if (*(start + j) < *(start + min))
                min = j;
        if (start[min] != start[i])  // 当找到的最小值需要交换时
        {
            int tmp = start[min];
            start[min] = start[i];
            start[i] = tmp;
        }
    }
}
```

# 插入排序 Insertion Sort

code:

```c++
void insertion_sort(int *start, int *end)
{
    for (int i = 0; start + i < end; i++)  // 从 start + i 到 end 是 待排部分
    {
        int tmp = start[i],  // 取待排的首个
        pos = i - 1;  // 找到要插入的位置
        for (; pos >= 0; pos--)
            if (start[pos] > tmp)
                start[pos+1] = start[pos];  // 后移以腾开要插入的位置
            else
                break;  // 找到位置
        start[pos+1] = tmp;  // 插入
    }
}
```

# 全排列 Full Permutation

code:

```c++
/*
参数：
    index: 现在正在为 p[index] 找合适的值
    n: n 阶全排列
    p[]: 暂存排列的数组
    exist[]: 保存是否已经使用过某个数字的布尔状态数组，需要初始化为全 false
功能：
    按升序输出 n 阶数字全排列，返回全排列个数
*/
int perm(int index, int n, int p[], bool exist[])
{
    int cnt = 0;
    if (index == n + 1)  // 递归边界
    {
        for (int i = 1; i <= n; i++)
            printf("%d", p[i]);
        printf("\n");
        cnt++;
    }
    else
        for (int x = 1; x <= n; x++)  // 枚举 1 ~ n 所有 x
            if (! exist[x])  // 若 x 未被使用，填在 p[index]
            {
                p[index] = x;
                exist[x] = true;
                cnt += perm(index + 1, n, p, exist);
                exist[x] = false;
            }
    return cnt;
}
```

# 二分查找 Binary Search

hint:

1. `二分查找的本质：查询有序序列第一个满足（或最后一个不满足）给定条件元素的位置`

2. `要注意的关键点：`

   * `while 循环中是 left <= right or left < right`
   * `接收参数 left，right 所代表的区间开闭`
   * `判断时的 array[mid] > or < or >= or <= x`
   * `不满足情况时的返回值`
   * `返回值返回什么`

code:

```c++
// search x in a[] from left to right (both ends included)
// return -1 if nothing was found
int binarySearch(int x, int a[], int left, int right)
{
    int mid;
    while (left <= right)  // to make mid cover all the possible points
    {
        mid = left + (right - left) / 2;  // using (left + right) / 2 might cause overflow
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid -1;
    }
    return -1;
}
```


```cpp
// find the first one who is equal to x from left to right (both ends included)
// return -1 if nothing was found
int lowerBound(int x, int a[], int left, int right)
{
    if (left > right) return -1;
    int mid;
    while (left < right)  // 保证结束时 left 和 right 具有相同值
    {
        mid = left + (right - left) / 2;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (a[left] == x)
        return left;
    else
        return -1;
}
```

```cpp
// find the first one who is equal to x from left (included) to right (excluded)
// return original right if no one bigger than x
int upperBound(int x, int a[], int left, int right)
{
    int mid, r = right;
    while (left < right)  // 保证结束时 left 和 right 具有相同值
    {
        mid = left + (right - left) / 2;
        if (a[mid] <= x)
            left = mid + 1;
        else
            right = mid;  // 不满足条件，所以不能 - 1
    }
    if (left >= r)
        return r;
    else
        return left;
}
```

```cpp
// 有序序列第一个满足（最后一个不满足）给定条件元素位置查询问题的模板
int sequentialProblemTemplate(int left, int right)
{
    int mid;
    bool condition; // 条件
    while (left < right)  // 最终 left == right
    {
        mid = left + (right - left) / 2;
        if (condition)  // 条件成立，且待查元素在右
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
```

# 快速幂 Fast Power

hint:

`运用位级运算优化：使用按位与判断奇数；使用位移运算模拟乘除法`

code:

```c++
// calculate a ^ b % c
LL fastPowerRecursion(LL a, LL b, LL c)
{
    if (a == 0 || c == 1) return 0;  // special judge
    if (b == 0) return 1;  // recursive boundary
    a %= c;  // optimization
    if (b & 1)  // if b is even
        return a * fastPowerRecursion(a, b - 1, c) % c;
    else
    {
        LL tmp = fastPowerRecursion(a, b / 2, c);
        return tmp * tmp % c;
    }
}
```

```cpp
// calculate a ^ b % c
// example: 99^6 == 99^2 * 99^4
LL fastPowerIteration(LL a, LL b, LL c)
{
    if (a == 0 || c == 1) return 0;  // special judge
    a %= c;
    LL ans = 1;
    while (b > 0)
    {
        if (b & 1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}
```

# 

hint:

1. ``

2. ``

code:

```c++

```

# 

hint:

1. ``

2. ``

code:

```c++

```

# 

hint:

1. ``

2. ``

code:

```c++

```