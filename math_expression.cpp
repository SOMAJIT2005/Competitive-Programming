#include <iostream>
using namespace std;
int main(){
    long long a,b,c; ;
    char x,y;
    cin >> a >> x >> b >> y >>c;
    if (x == '+' && y == '=') {
        if (a + b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a + b << endl;
        }
    } else if (x == '-' && y == '=') {
        if (a - b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a - b << endl;
        }
    } else if (x == '*' && y == '=') {
        if (a * b == c) {
            cout << "Yes" << endl;
        } else {
            cout << a * b << endl;
        }
    }
}