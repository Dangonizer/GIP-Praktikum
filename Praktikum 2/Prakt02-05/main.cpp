#include <iostream>
using namespace std;
int main()
{
    char letter;
    cout << "Please insert letter:\n";
    cin >> letter;
    cout << "The letter " << letter << " has the position " << letter - 96 << " in the alphabet.\n";
    system("PAUSE");
    return 0;
}