#include <iostream>
using namespace std;

// 函数声明
int findMaxInArray(int *arr, int size);

int main()
{
    // 假设我们要存储的整数数量
    int size = 5;

    // 动态分配数组
    int *arr = new int[size];

    // 填充数组
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 10; // 示例数据，每个元素是索引的10倍
    }

    // 调用函数找到最大整数
    int maxVal = findMaxInArray(arr, size);

    // 显示结果
    cout << "数组中的最大整数是: " << maxVal << endl;

    // 释放内存
    delete[] arr;

    return 0;
}

// 函数定义，用于找到数组中的最大整数
int findMaxInArray(int *arr, int size)
{
    if (size <= 0 || arr == nullptr)
    {
        throw invalid_argument("数组大小必须大于0且数组不能为nullptr");
    }

    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}