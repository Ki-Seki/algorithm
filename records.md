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

# 模板 Template

hint:

1. ``

2. ``

code:

```c++

```
