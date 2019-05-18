//位排序
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
#define MAX 20

int main()
{
    vector<int> vec = {5, 1, 2, 13, 7, 10, 0, 20, 16, 9};
    //创建一个位图类，并默认全部值为0
    bitset<MAX+1> bitset1;
    //将对应的为置为1
    for (int i = 0; i < vec.size(); i++)
    {
        bitset1.set(vec[i]);
    }
    //输出排序结果
    for (int i = 0; i < MAX+1; i++)
    {
        //判断第n位是否为1，若为1，则说明有待排序列中出现了改值,然后输出即可
        if (bitset1.test(i))
        {
            cout << i << ", ";
        }
    }
    cout << endl;
    return 0;
}

