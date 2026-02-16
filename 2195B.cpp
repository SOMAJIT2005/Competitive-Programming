#include <iostream>
#include <vector>
using namespace std;

int get_odd_root(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool flag = true;
        
        for (int i = 0; i < n; i++) {
            int index = i + 1; 
            int value = a[i];      

            if (get_odd_root(index) != get_odd_root(value)) {
                flag = false;
                break; 
            }
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}