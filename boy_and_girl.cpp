#include <iostream>
using namespace std;
int main(void){
    char str[100];
    cin >> str;
    int count = 0;
    int freq[256]= {0}; // ASCII values from 0 to 255
    for (int i = 0; str[i]!= '\0'; i++)
    {
        unsigned char ch = str[i];
        if (freq[ch] == 0)
        {
            count++;
            freq[ch] = 1;
        }

    }
    
    if (count % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
    

}