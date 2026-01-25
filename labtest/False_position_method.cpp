#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double function(double x)
{
    return 4 * pow(x, 3) - 6 * pow(x, 2) + 7 * x - 2.3;
}

void bisection(double a, double b, double error)
{
    if (function(a) * function(b) >= 0)
    {
        cout << "Wrong Assumption." << endl;
        return;
    }

    cout << "----------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "Iteration"
         << setw(12) << "xl"
         << setw(12) << "xu"
         << setw(12) << "xr"
         << setw(15) << "ea (%)" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    double c = 0, old_c = 0;
    double apperror = 100;
    int iteration = 0;
    while (apperror >= error)
    {

        old_c = c;
        c = b- (function(b)*(a-b))/(function(a)-function(b));

        apperror = abs((c - old_c) / c) * 100;

        cout << fixed << setprecision(5);
        cout << left << setw(10) << iteration
             << setw(12) << a
             << setw(12) << b
             << setw(12) << c
             << setw(15) << apperror << endl;

        if (function(a) * function(c) < 0)
        {
            b = c;
        }
        else if (function(a) * function(c) == 0)
        {
            cout << "Exact Root is: " << c << endl;
            return;
        }

        else
        {
            a = c;
        }

        iteration++;
    }

    cout << "Root is: " << c << endl;
}
int main()
{
    double a, b, error;
    cout << "Enter the value of a and b: ";
    cin >> a >> b;
    cout << "Enter the acceptable error: ";
    cin >> error;

    bisection(a, b, error);

    return 0;
}