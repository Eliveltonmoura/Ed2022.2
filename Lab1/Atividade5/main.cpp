#include <iostream>

using namespace std;

int main()
{

    int i, j, m[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> m[i][j];
        }
    }
    int diagonal = 0, subdiagonal = 0, col1 = 0, col2 = 0, col3 = 0, lin1 = 0, lin2 = 0, lin3 = 0;

    diagonal = m[0][0] + m[1][1] + m[2][2];
    subdiagonal = m[0][2] + m[1][1] + m[2][0];
    col1 = m[0][0] + m[1][0] + m[2][0];
    col2 = m[0][1] + m[1][1] + m[2][1];
    col3 = m[0][2] + m[1][2] + m[2][2];
    lin1 = m[0][0] + m[0][1] + m[0][2];
    lin2 = m[1][0] + m[1][1] + m[1][2];
    lin3 = m[2][0] + m[2][1] + m[2][2];

    if ((diagonal != subdiagonal && diagonal != col1 && diagonal != col2) && (diagonal != col3 && diagonal != lin1 && diagonal != lin2 && diagonal != lin3))
        cout << "não" << endl;
    else
        cout << "sim" << endl;
}