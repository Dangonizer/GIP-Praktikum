#include <iostream>
#include <string>
using namespace std;

const int sudoku_groesse = 9;
const int eingabe_groesse = 11;

bool pruefe_spalten(int sudoku[][sudoku_groesse])
{
    bool correct = true;
    for (int i = 0; i < sudoku_groesse; i++)
    {
        int count[9] = {0};
        for (int i2 = 0; i2 < sudoku_groesse; i2++)
        {
            count[sudoku[i2][i] - 1] += 1;
        }
        for (int j = 0; j < 9; j++)
        {
            if (count[j] > 1)
            {
                cout << "Spalte " << i << ": Zahl " << j + 1 << " kommt mehrfach vor.\n";
                correct = false;
            }
            else if (count[j] < 1)
            {
                cout << "Spalte " << i << ": Zahl " << j + 1 << " kommt nicht vor.\n";
                correct = false;
            }
        }
    }
    return correct;
}

bool pruefe_zeilen(int sudoku[][sudoku_groesse])
{
    bool correct = true;
    for (int i = 0; i < sudoku_groesse; i++)
    {
        int count[9] = {0};
        for (int i2 = 0; i2 < sudoku_groesse; i2++)
        {
            count[sudoku[i][i2] - 1] += 1;
        }
        for (int j = 0; j < 9; j++)
        {
            if (count[j] > 1)
            {
                cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt mehrfach vor.\n";
                correct = false;
            }
            else if (count[j] < 1)
            {
                cout << "Zeile " << i << ": Zahl " << j + 1 << " kommt nicht vor.\n";
                correct = false;
            }
        }
    }
    return correct;
}

bool pruefe_bloecke(int sudoku[][sudoku_groesse])
{
    bool correct = true;
    for (int block = 0; block < sudoku_groesse; block++)
    {
        int count[9] = {0};
        for (int zeile = block / 3 * 3; zeile <= block / 3 * 3 + 2; zeile++)
        {
            for (int spalte = block % 3 * 3; spalte <= block % 3 * 3 + 2; spalte++)
            {
                count[sudoku[zeile][spalte] - 1] += 1;
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (count[j] > 1)
            {
                cout << "Block " << block << ": Zahl " << j + 1 << " kommt mehrfach vor.\n";
                correct = false;
            }
            else if (count[j] < 1)
            {
                cout << "Block " << block << ": Zahl " << j + 1 << " kommt nicht vor.\n";
                correct = false;
            }
        }
    }
    return correct;
}

void konvertiere(string eingabe[], int sudoku[][sudoku_groesse])
{
    for (int i = 0, posy = 0; i < 11; i++)
    {
        if (i != 3 && i != 7)
        {
            for (int j = 0, posx = 0; j < eingabe[i].length(); j++)
            {
                if (eingabe[i].at(j) > 47 && eingabe[i].at(j) < 58)
                {
                    sudoku[posy][posx] = eingabe[i].at(j) - 48;
                    posx += 1;
                }
            }
            posy += 1;
        }
    }
}

int main()
{
    int sudoku[sudoku_groesse][sudoku_groesse] = {0};
    string eingabe[eingabe_groesse];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;
    for (int i = 0; i < eingabe_groesse; i++)
        getline(cin, eingabe[i]);

    konvertiere(eingabe, sudoku);

    bool ps = pruefe_spalten(sudoku);
    bool pz = pruefe_zeilen(sudoku);
    bool pb = pruefe_bloecke(sudoku);

    if (ps && pz && pb)
        cout << "Das Sudoku ist gueltig." << endl;

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

.1.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.9
*/