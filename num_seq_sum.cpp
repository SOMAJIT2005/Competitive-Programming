#include <iostream>
using namespace std;
int main(){
    int m, n;
    int sum = 0;
    while (cin>>m>>n)
    {
        if (m<=0 || n <=0)
        {
            break;
        }
        
        int start = min(m, n);
        int end = max(m, n);
        for (int i = start; i <= end; i++)
        {
            cout << i << " ";
            sum += i;
        }
        cout<< "sum ="<< sum << endl;
        sum = 0; // Reset sum for the next input

    }
    
    
        
    }
    
    
    
    
