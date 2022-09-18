#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);
        bool ehMauiusculo = isupper(line[0]);
        for (i = 1; i < (int)line.size(); i++)
        {
            if (line[i] != ' ' && islower(line[i - 1]))
            {
                line[i] == toupper(line[i]);
            }
            else if (line[i - 1] != ' ' && isupper(line[i - 1]))
            {
                line[i] = tolower(line[i])
            }
            else if (line[i])
            {
            }
        }
    }
}