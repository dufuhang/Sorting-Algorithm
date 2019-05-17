//插入排序
#include <iostream>
#include <vector>
using namespace std;

//插入排序
template <typename T>
void insertionSort(vector<T>& vec)
{
    if (vec.size() == 0)
    {
        return;
    }
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = i;j > 0; j--)
        {
            if (vec[j] < vec[j-1])
            {
                swap(vec[j], vec[j-1]);
            }
        }
    }
}

int main()
{

    return 0;
}