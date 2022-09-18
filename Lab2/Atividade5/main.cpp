#include <iostream>
#include <cstring>
using namespace std;
int main()
{

    string palavra;
    int i;
    getline(cin, palavra);

    for (i = 0; i < size(palavra); i++)
    {
        palavra = palavra[i - 1];
        cout << palavra[i];
    }
}
