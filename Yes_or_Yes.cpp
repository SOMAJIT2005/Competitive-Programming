#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        int countY = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'Y')
            {
                countY++;
            }
        }
        if (countY <= 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}