#include <iostream>
using namespace std;
int main()
{
    int zahl1, min, max, minposition, maxposition;
    for (int i = 1; i < 6; i++)
    {
        cout << "Please insert the " << i << ". number.\n";
        cin >> zahl1;
        if (i == 1)
        {
            min = max = zahl1;
            minposition = maxposition = i;
        }
        if (zahl1 < min)
        {
            min = zahl1;
            minposition = i;
        }
        if (zahl1 > max)
        {
            max = zahl1;
            maxposition = i;
        }
    }
    cout << "The " << minposition << ". number was the smallest number with the value " << min << ".\n";
    cout << "The " << maxposition << ". number was the biggest number with the value " << max << ".\n";
    system("PAUSE");
    return 0;
}
