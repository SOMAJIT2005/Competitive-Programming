#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    char str[n][100];
    for (int i = 0; i < n; i++)
    {
        //getline(cin, str[i]);// only works in string declairation not in 2d char array
        cin>> str[i];
    }

    for ( int i = 0; i < n; i++)
    {
        int x = strlen(str[i]);
        str[i][x-2] = 'i';
        str[i][x-1] = '\0';
        cout<< str[i] << endl;
    }
}