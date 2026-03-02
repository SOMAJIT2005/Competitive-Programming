#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void printMatrix(const vector<vector<double>>& M, const string& name) {
    cout << name << ":" << endl;
    for (const auto& row : M) {
        for (double val : row) {
            if (abs(val) < 1e-9) val = 0.0;
            cout << setw(10) << fixed << setprecision(4) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const vector<double>& v, const string& name) {
    cout << name << ": [ ";
    for (double val : v) {
        if (abs(val) < 1e-9) val = 0.0;
        cout << fixed << setprecision(4) << val << " ";
    }
    cout << "]" << endl << endl;
}

void LUDecomposition(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U = A; 

    cout << "LU DECOMPOSITION (GAUSS ELIMINATION)\n\n";

    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
    }

    cout << "Finding L and U" << endl;

    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            int maxRow = i;
            double maxVal = abs(U[i][i]);
            for (int k = i + 1; k < n; k++) {
                if (abs(U[k][i]) > maxVal) {
                    maxVal = abs(U[k][i]);
                    maxRow = k;
                }
            }

            if (maxRow != i) {
                swap(U[i], U[maxRow]);
                swap(b[i], b[maxRow]);
                for (int j = 0; j < i; j++) {
                    swap(L[i][j], L[maxRow][j]);
                }
                cout << "  -> Swapped row " << i + 1 << " with row " << maxRow + 1 << endl;
            }

            printMatrix(U," Matrix U after pivoting");
        }

        if (abs(U[i][i]) < 1e-9) {
            cout << "Error: Zero pivot at U[" << i+1 << "][" << i+1 << "].\n";
            return;
        }

        bool eliminated = false;
        for (int k = i + 1; k < n; k++) {
            if (abs(U[k][i]) > 1e-9) {
                double factor = U[k][i] / U[i][i];
                L[k][i] = factor;
                
                cout << "  Row " << k+1 << " = Row " << k+1 << " - (" << fixed << setprecision(4) << factor << ") * Row " << i+1 << endl;
                for (int j = i; j < n; j++) {
                    U[k][j] -= factor * U[i][j];
                }
                eliminated = true;
            }
        }
        
        if (eliminated) {
            cout << endl;
            printMatrix(U,"after elimination :");
        }
    }
    
    cout << endl;
    printMatrix(U, "Final Upper Triangular Matrix (U)");
    printMatrix(L, "Final Lower Triangular Matrix (L)");

    cout << "Forward Substitution (L * D = B)" << endl;
    vector<double> y(n, 0.0);
    for (int i = 0; i < n; i++) {
        double sum = b[i];
        for (int j = 0; j < i; j++) {
            sum -= L[i][j] * y[j];
        }
        y[i] = sum;
        cout << "  d[" << i+1 << "] = " << y[i] << endl;
    }
    cout << endl;

    cout << "Backward Substitution (U * X = D)" << endl;
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        double sum = y[i];
        for (int j = i + 1; j < n; j++) {
            sum -= U[i][j] * x[j];
        }
        x[i] = sum / U[i][i];
        cout << "  x[" << i+1 << "] = " << x[i] << endl;
    }
    
    cout << endl;
    printVector(x, "Final Solution Vector (x)");
}

int main() {
    int n;
    cout << "Enter the number of unknowns: ";
    cin >> n;

    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
    
    cout << "Enter the augmented matrix :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> augmentedMatrix[i][j];
        }
    }

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = augmentedMatrix[i][j];
        }
        b[i] = augmentedMatrix[i][n];
    }

    cout << "\n\n";
    LUDecomposition(A, b);

    return 0;
}