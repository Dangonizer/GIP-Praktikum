#include <iostream>
using namespace std;
int main()
{
    double value = 0;
    int method = 0;
    double result = 0;
    cout << "Please insert input value:\n";
    cin >> value;
    cout << "Please choose conversion method:\n1: Celsius to Fahrenheit\n2: Meter to Foot\n3: Euro to Dollar\n";
    cin >> method;
    result = 0.5 * (method - 2) * (method - 3) * (value * 1.8 + 32) + (-1) * (method - 1) * (method - 3) * (value * 3.2808) + 0.5 * (method - 1) * (method - 2) * (value * 1.2957);
    cout << "The result is: " << result << endl;
    system("PAUSE");
    return 0;
}