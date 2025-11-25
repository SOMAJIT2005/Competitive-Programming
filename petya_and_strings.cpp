#include<iostream>
#include<string>
using namespace std;
int check(string a, string b, int l){
    int count = 0;
    for(int i = 0; i<l; i++)
    { if(a[i]==b[i] || (int)a[i] == (int)b[i]+32||(int)a[i]+32 == (int)b[i])
    { count++;}
    }
    if(count == l){
        return true;}
        else{ return false;}
}
int main(){
    string a, b;
    cin>> a >> b;
    int l = a.length();
   if(!check(a,b,l)){
    for (int i = 0; i < l; i++)
    {
        char ch1 = a[i];
        char ch2 = b[i];
        if(ch1 >= 'A' && ch1 <='Z')
        {ch1 = (int)ch1+32;}
        
         if(ch2 >= 'A' && ch2 <='Z')
         {ch2 = (int)ch2 +32;}
         
         if(ch1>ch2)
         {cout<<1; 
         return 0;}
         else if(ch1<ch2){ cout<< -1;
         return 0;}
    }
   }
   
    cout<< 0;

    
    
}



/*or

int main(){
string a, b;
cin>>a>>b;
int l = a.length();
for(int i = 0 ; i < l ; i++)
{
char ch1 = tolower(a[i]);
char ch2 = tolower(b[i]);
if(ch1<ch2){
cout<< -1;
return 0;
}
else if(ch1>ch2){
cout<< 1;
return 0;}
}
cout<< 0;
}*/
