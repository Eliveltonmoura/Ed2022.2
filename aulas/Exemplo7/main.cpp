#include <iostream>
#include "list.h"
#include <vector>
using namespace std;
void print(list<float> &lst)
{
    for (int i = 0; i < lst.size(); i++)
    {
        cout << lst[i] << " ";
    }
    cout << endl;
}

int main()
{

    list<int> list;
    for (int i = 0; i < 9; i++)
    {
        list.pop_back(i);
    }
    for (int i = 0; i < list.size(); i++)
    {
        cout<< list[i]<<endl;
        
    }
    

    for (list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }

    // list<float> list;

    // for (int i = 1; i <= 9; i++)
    // {
    //     list.push_back(i);
    // }

    // print(list);

    // while (!list.empty())
    // {
    //     list.pop_back();
    //     print(list);
    // }
}