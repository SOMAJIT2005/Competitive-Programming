#include<bits/stdc++.h>
using namespace std;

long long Sum(long long n){
    long long sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long x;
        cin>>x;
        int count = 0;

        for (long long i = x; i <= x + 100; i++)
        {
            if (i - Sum(i) == x)
            {
                count++;
            }
        }

        cout<<count<<endl;
    }
}