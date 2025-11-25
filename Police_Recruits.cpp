#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int crime = 0;
    int police = 0;
    while (t--)
    {
        int a;
        cin>>a;
        if(a==-1){
        if(police){
            police--;
            continue;
            
        }
            crime++;
        }
        else{
            police+=a;
        }
    }
    cout<<crime<<endl;
    return 0;
    
}