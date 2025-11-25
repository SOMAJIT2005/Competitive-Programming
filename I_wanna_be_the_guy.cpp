#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    set<int>n;

    int p;
    cin>>p;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin>>x;
        n.insert(x);
    }
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int y;
        cin>>y;
        n.insert(y);
    }

    if (n.size()==t)
    {
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }
    
    
    

}