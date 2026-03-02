#include<bits/stdc++.h>

using namespace std;

void printMatrix(const vector<vector<double>>& a, const vector<double>& b, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "";
        for (int j = 0; j < n; ++j) {
            double val = a[i][j];
            if (abs(val) < 1e-9) val = 0.0;
            cout << setw(8) << fixed << setprecision(2) << val << " ";
        }
        cout << " | " << setw(8) << fixed << setprecision(2) << b[i] << "\n";
    }
    cout << endl;
}

void Gauss(vector<vector<double>> a, vector<double> b, int n, vector<double>& x) {
    cout << "\nGAUSSIAN ELIMINATION\n";
    printMatrix(a, b, n);

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];

            for (int j = k + 1; j < n; j++) {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
            a[i][k] = 0.0; 
            b[i] = b[i] - factor * b[k];

            printMatrix(a, b, n);
        }
    }

    x[n - 1] = b[n - 1] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--) {
        double sum = b[i];
        for (int j = i + 1; j < n; j++) {
            sum = sum - a[i][j] * x[j];
        }
        x[i] = sum / a[i][i];
    }
}

void GaussJordan(vector<vector<double>> a, vector<double> b, int n, vector<double>& x) {
    cout << "\n GAUSS-JORDAN ELIMINATION\n";
    printMatrix(a, b, n);

    for (int k = 0; k < n; ++k) {
        double d = a[k][k];

        for (int j = 0; j < n; ++j) {
            a[k][j] = a[k][j] / d;
        }
        b[k] = b[k] / d;

        printMatrix(a, b, n);

        for (int i = 0; i < n; ++i) {
            if (i != k) { 
                double factor = a[i][k]; 
                if (abs(factor) > 1e-9) {
                    for (int j = k; j < n; ++j) {
                        a[i][j] = a[i][j] - factor * a[k][j];
                    }
                    a[i][k] = 0.0; 
                    b[i] = b[i] - factor * b[k];

                    printMatrix(a, b, n);
                }
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        x[k] = b[k]; 
    }
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    if (!(cin >> n) || n <= 0) return 1;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n);
    vector<double> x_gauss(n);
    vector<double> x_jordan(n);

    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j]; 
        }
        cin >> b[i];        
    }
    
    Gauss(a, b, n, x_gauss);
    GaussJordan(a, b, n, x_jordan);
    
    cout << " (Gauss):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(4) << x_gauss[i] << endl;
    }

    cout << "\n(Gauss-Jordan):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(4) << x_jordan[i] << endl;
    }
    
    return 0;
}