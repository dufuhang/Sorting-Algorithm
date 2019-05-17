//冒泡排序
//时间复杂度为O(N^2),是稳定排序算法。
#include <iostream>
#include <vector>
using namespace std;
//冒泡排序#1
template <typename T>
void BubbleSort(vector<T>& vec)
{
    //排序的趟数为size()-1
    for (int i = 0; i < vec.size() - 1; i++)
    {
        //每趟排序都会使一个元素有序，所以每趟排序需要比较的次数为size()-1-i
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
            }
        }
    }
}
//冒泡排序#2(改进版)
template <typename T>
void BubbleSort2(vector<T>& vec)
{
    //设立一个哨兵，观察每一趟排序是否有元素交换。若无，则说明已经有序,算法结束。
    //若在某趟之后，没有进行交换，则说明后续比较无需进行。哨兵的存在可以省去无用的比较，节省时间。
    bool flag = true;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        //flase:无交换，已经有序;true：有交换,仍然无序
        flag = false;
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
                flag = true;
            }
        }
        //判断哨兵状态
        if (!flag)
        {
            //退出循环，算法结束
            break;
        }
    }
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
    vector<int> vec = {20, 40, 30, 10, 60, 50};
    cout << "Before: ";
    show(vec);
    BubbleSort2(vec);
    cout << "After: ";
    show(vec);
    return 0;
}