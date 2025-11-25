#include <bits/stdc++.h>
using namespace std;
int unique_digit(int year)
{
    set<int> digits;
    while (year)
    {
        digits.insert(year%10);
        year/=10;
    }
    if (digits.size()==4)
    {
        return true;
    }
    else{
        return false;
    }
    
    
}
int main(){
    int n;
    cin>>n;

    n++;
    while (true)
    {
        if (unique_digit(n))
        {
            cout<<n;
            break;
        }

        n++;
    }
}
