#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string num1_str = "", num2_str = "";
    char op = ' ';
    bool operatorFound = false;

   
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            op = s[i];
            operatorFound = true;
            continue; 
        }

        if (!operatorFound) {
            num1_str += s[i]; 
        } else {
            num2_str += s[i]; 
        }
    }

    
    int a = stoi(num1_str);
    int b = stoi(num2_str);

    if (op == '+') {
        cout << a + b << endl;
    } else if (op == '-') {
        cout << a - b << endl;
    }

    return 0;
}