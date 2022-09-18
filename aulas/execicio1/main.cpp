#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    for (int i = 0; i < (int)input.length(); i++)
    {
        if (input[i] == ' ' || input[i] == '\t')
        {
            // int cont = i;
            while (input[i] == ' ' || input[i] == '\t')
            {
                i++;
            }
            cout << " ";
            i--;
        }
        else
        {
            cout << input[i];
        }
    }
    cout << endl;
}