#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int s = 0, d =0, f1 =1;
    while (!v.empty())
    {
        if (f1 == 1)
        {
            if (*v.begin()> v.back())
        {
            s += *v.begin();
            v.erase(v.begin()); // remove the first element
        }
        else{
            s += v.back();
            v.erase(v.end()-1); // remove the last element
            //v.pop_back;
            f1 =2;
        }
        }
        else {
            if (*v.begin()> v.back())
            {
                d+= *v.begin();
                v.erase(v.begin()); // remove the first element
            }
            else{
                d += v.back();
                v.pop_back(); // remove the last element
            }
            f1 = 1;
        }
        
    }
    cout << s << " " << d << endl;
      
}