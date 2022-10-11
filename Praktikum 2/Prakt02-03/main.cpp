#include <iostream>
using namespace std;
int main() {
    double value=0;
    cout << "Please insert amount of money in Euro:\n";
    cin >> value;
    value=value*1.2957;
    cout << "The amount of money in US Dollar is: " << value << endl;
    system("PAUSE");
    return 0;
}
