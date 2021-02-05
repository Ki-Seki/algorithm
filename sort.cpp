#include <iostream>
using namespace std;

void select_sort(int *start, int *end)
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

int main()
{
    int a[5] = {5, 3, 4, 6, 0};
    // select_sort(a, a+5);
    insertion_sort(a, a + 5);
    return 0;
}