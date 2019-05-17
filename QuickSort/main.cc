//快速排序
//时间复杂度:最坏O(N^2), 平均O(N * logN)。为不稳定排序算法
#include <iostream>
#include <vector>
using namespace std;

//#1递归
template <typename T>
void quickSort_recursive(vector<T>& vec, int left, int right)
{
    //若数组为空，算法结束
    if (left >= right)
    {
        return;
    }
    int pivot = vec[left];  //设置基准点为首位的值
    int start = left;   //设置左边的哨兵
    int end = right;    //设置右边的哨兵
    //只要左哨兵小于右哨兵，说明没有遍历完，算法继续
    while (start < end)
    {
        //从右往左寻找小于基准点的值。start < end 是为了避免基准点右边的值全部大于基准点，如3, 7, 6, 5。防止end越界访问
        while (start < end && vec[end] > pivot)
        {
            end--;
        }
        //上述循环退出，说明1、start >= end或则2、vecp[end] < pivot
        //此判断为了防止第一种情况，保证是第二种情况
        if (start < end)
        {
            //交换基准点和符合条件的值
            swap(vec[end], vec[start]);
            //此时start处的值已为小于基准点的值，所以直接从下一位开始遍历
            start++;
        }
        //从左往右寻找大于基准点的值
        while (start < end && vec[start] < pivot)
        {
            start++;
        }
        if (start < end)
        {
            swap(vec[start], vec[end]);
            end--;
        }
    }
    //进入递归,已经就位的基准点将数组分为两部分，分别对其进行快速排序。
    //此时start == end,所以end -1 或者 start - 1都可以。下同理
    quickSort_recursive(vec, left, start - 1);
    quickSort_recursive(vec, start + 1, right);
}
//遍历输出
void show(const vector<int>& vec)
{
    for (int num : vec)
    {
        cout << num << ",";
    }
    cout << endl;
}
int main()
{
    vector<int> vec = {3, 7, 6, 5};
    cout << "Before: ";
    show(vec);
    quickSort_recursive(vec, 0, (int)vec.size() - 1);
    cout << "After: ";
    show(vec);
    return 0;
}

