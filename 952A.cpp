#include <iostream>
using namespace std;
int main()
{
    string a, b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a == b)
        {
            cout << a << " " << b << endl;
            continue;
        }

        char temp = a[0];
        a[0] = b[0];
        b[0] = temp;
        cout << a << " " << b << endl;
    }
}