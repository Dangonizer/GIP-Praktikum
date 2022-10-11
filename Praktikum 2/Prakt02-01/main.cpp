#include <iostream>
using namespace std;
int main() {
    double value=0;
    cout << "Please insert temperature in Celsius:\n";
    cin >> value;
    value=value*1.8+32;
    cout << "The temperature in Fahrenheit is: " << value << endl;
    system("PAUSE");
    return 0;
}
