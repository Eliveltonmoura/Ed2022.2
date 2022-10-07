#include <iostream>
#include <vector>
using namespace std;

// intereito

void print(const vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}
void erase_value(vector<int> &vec, int value)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it == value)
        {
            vec.erase(it);
            break;
        }
    }
}
void erase_value2(vector<int> &vec, int value)
{
    for (auto it = vec.begin(); it != vec.end();)
    {
        if (*it == value)
        {
            vec.erase(it);
        }
        else
        {
            it++;
        }
    }
}

int main()
{

    vector<int> vec{1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 5, 5};

    // cout << *(vec.end() - 6) << endl;

    print(vec);
    // // auto it = vec.begin();
    // // vec.insert(it, 777);
    // // print(vec);

    // erase_value(vec, 5);
    erase_value2(vec, 5);
    print(vec);
}