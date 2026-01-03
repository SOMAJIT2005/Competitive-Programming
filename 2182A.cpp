#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n >> s;
        if (s.find("2025")!=string::npos && s.find("2026")==string::npos)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        
    }
}
