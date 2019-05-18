//插入排序
//时间复杂度为O(N^2),稳定算法
#include <iostream>
#include <vector>
using namespace std;

//插入排序
template <typename T>
void insertionSort(vector<T>& vec)
{
    //若数组长度为0，算法直接结束
    if (vec.size() == 0)
    {
        return;
    }
    //默认第一个元素为有序
    for (int i = 1; i < vec.size(); i++)
    {
        //当前i为无序组的第一个元素。将其一一与有序组比较（从后往前）
        for (int j = i;j > 0; j--)
        {
            //若带插入元素小于有序组中的元素，则交换（相当于将有序组元素后移，插入待插元素）,直到到达合适位置
            if (vec[j] < vec[j-1])
            {
                swap(vec[j], vec[j-1]);
            }
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
    vector<int> vec = {89, 78, 67, 1, 32, 1, 46, 99999, 992};
    cout << "Before: ";
    show(vec);
    insertionSort(vec);
    cout << "After: ";
    show(vec);
    return 0;
}