//选择排序
//时间复杂度为O(N^2),稳定算法
#include <iostream>
#include <vector>
using namespace std;

//选择排序
template <typename T>
void selectionSort(vector<T>& vec)
{
    int order_tail; //有序区末尾位置
    int disorder_front; //无序区开始位置
    int min;    //最小值位置
    //若向量长度为0，算法直接结束
    if (vec.size() == 0)
    {
        return;
    }
    //！注意这点！
    //i为有序区末尾的下一个位置，即无序区的头。
    for (int i = 0; i < vec.size(); i++)
    {
        //初始以无序区的首位置为最小值
        min = i;
        //在无序区中头的下一个位置开始寻找最小值
        for (int j = i + 1; j < vec.size(); j++)
        {
            //找到更小的值，将位置赋给min
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        //将无序区的头与最小值交换
        //此时，无序区的头被纳入有序区的尾
        swap(vec[i], vec[min]);
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
    vector<int> vec = {45, 798, 1, 0, -1, 34534, 5, 2, 765, 1};
    cout << "Before: ";
    show(vec);
    selectionSort(vec);
    cout << "After: ";
    show(vec);
    return 0;
}
