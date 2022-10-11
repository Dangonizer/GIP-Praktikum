#include <iostream>
using namespace std;
int main() {
    double value=0;
    cout << "Please insert length in Meter:\n";
    cin >> value;
    value=value*3.2808;
    cout << "The length in Foot is: " << value << endl;
    system("PAUSE");
    return 0;
}
