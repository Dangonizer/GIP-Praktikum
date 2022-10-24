#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input[11];
    int sudoku[9][9] = {0};
    cout << "Please insert sudoku:\n";
    for (int i = 0; i < 11; i++)
    {
        getline(cin, input[i]);
    }
    for (int i = 0, posy = 0; i < 11; i++)
    {
        for (int j = 0, posx = 0; j < input[i].length(); j++)
        {
            if (input[i].at(j) > 47 && input[i].at(j) < 58)
            {
                sudoku[posy][posx] = input[i].at(j) - 48;
                posx += 1;
            }
        }
        if (i != 3 && i != 7)
        {
            posy += 1;
        }
    }
    cout << "The Sudoku is;\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << ";" << sudoku[i][j];
            if (j == 2 || j == 5)
            {
                cout << ";//";
            }
        }
        cout << endl;
        if (i == 2 || i == 5)
        {
            cout << "=======//=======//=======\n";
        }
    }
    system("PAUSE");
    return 0;
}
/*
.5.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.1
*/