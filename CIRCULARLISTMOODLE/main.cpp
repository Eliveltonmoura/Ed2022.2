#include <iostream>
#include "CircularList.h"
using namespace std;

void print(const CircularList &lst)
{
    for (int i = 0; i < lst.size(); ++i)
        cout << lst[i] << " ";
    cout << endl;
}

int main()
{
    CircularList lst;

    // for (int i = 1; i <= 9; ++i)
    //     lst.push_back(i * 0.5);
    // print(lst);
    // cout << lst.size() << endl;

    // cout << endl;

    // lst.clear();
    // cout << lst.size() << endl;
    // print(lst);

    /*
    while(!lst.empty()) {
        lst.pop_back();
        print(lst);
    }*/

    for (int i = 1; i <= 9; i++)
    {
        lst.insert(1, i);

                print(lst);
    }
}