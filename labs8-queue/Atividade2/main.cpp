
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // int a{0};
    // int b{0};
    queue<string> times, ganhou;

    for (int i = 0; i < 16; i++)
    {
        times.push('A' + i);
    }
    for (int i = 0; i <= 15; i++)
    {
        cout << times.front() << endl;
    }

    /*


        for (int j = 0; j < 4; j++)
        {

            if (ganhou.empty())
            {
                while (!times.empty())
                {
                    cin >> a >> b;
                    if (a > b)
                    {
                        ganhou.push(times.front());
                        times.pop();
                        times.pop();
                    }
                    else
                    {
                        times.pop();
                        ganhou.push(times.front());
                        times.pop();
                    }
                }
            }
            if (times.empty())
            {
                while (!ganhou.empty())
                {
                    cin >> a >> b;
                    if (a > b)
                    {
                        times.push(ganhou.front());
                        ganhou.pop();
                        ganhou.pop();
                    }
                    else
                    {
                        times.pop();
                        times.push(ganhou.front());
                        ganhou.pop();
                    }
                }
            }
        }

        cout<< ganhou.
        */
}