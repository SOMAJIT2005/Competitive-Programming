#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    while (t--) {
        string new_s = s; 
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'B' && s[i + 1] == 'G') {
                new_s[i] = 'G';
                new_s[i + 1] = 'B';
            }
        }
        s = new_s;
    }

    cout << s << endl;
    return 0;
}