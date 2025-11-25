#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d;
    cin>> a >> b >> c >> d;
    long long result = 1;
    result = (result * a)%100;//Modular multiplication 
    result = (result * b)%100;//Modular multiplication
    result = (result * c)%100;//Modular multiplication
    result = (result * d)%100;//Modular multiplication
    cout<< setw(2) <<setfill('0')<< result << endl;//setw(2) sets the width of the output to 2 characters, and setfill('0') fills with leading zeros if necessary
    //setw(2) sets the width of the output to 2 characters, and setfill('0') fills with leading zeros if necessary

}