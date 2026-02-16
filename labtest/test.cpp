#include <bits/stdc++.h>

using namespace std;

const long double PI = 3.14159265358979323846;

const long double h = 0.000000001;
string preprocess(string s)
{
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        res += s[i];
        if (i + 1 < s.length())
        {
            if (isdigit(s[i]) && (s[i + 1] == 'x' || isalpha(s[i + 1])))
            {
                res += '*';
            }
            else if (s[i] == ')' && (s[i + 1] == 'x' || isdigit(s[i + 1])))
            {
                res += '*';
            }
            else if (s[i] == 'x' && s[i + 1] == '(')
            {
                res += '*';
            }
        }
    }
    return res;
}

class ExpressionParser
{
    string expr;
    int pos;
    double variableValue;

    char peek()
    {
        if (pos < expr.length())
            return expr[pos];
        return 0;
    }

    char get()
    {
        char c = peek();
        if (pos < expr.length())
            pos++;
        return c;
    }

    bool match(string funcName)
    {
        if (expr.substr(pos, funcName.length()) == funcName)
        {
            pos += funcName.length();
            return true;
        }
        return false;
    }

    double parseNumber()
    {
        string numStr = "";
        while (isdigit(peek()) || peek() == '.')
        {
            numStr += get();
        }
        if (numStr.empty())
            return 0;
        return stod(numStr);
    }

    double parseFactor()
    {
        if (peek() == '+')
        {
            get();
            return parseFactor();
        }
        if (peek() == '-')
        {
            get();
            return -parseFactor();
        }

        double result = 0;

        if (peek() == '(')
        {
            get();
            result = parseExpression();
            if (peek() == ')')
                get();
        }
        else if (peek() == 'x')
        {
            get();
            result = variableValue;
        }
        else if (match("sin"))
            result = sin(parseFactor());
        else if (match("cos"))
            result = cos(parseFactor());
        else if (match("tan"))
            result = tan(parseFactor());
        else if (match("csc"))
            result = 1.0 / sin(parseFactor());
        else if (match("sec"))
            result = 1.0 / cos(parseFactor());
        else if (match("cot"))
            result = 1.0 / tan(parseFactor());
        else if (match("log"))
            result = log10(parseFactor());
        else if (match("ln"))
            result = log(parseFactor());
        else if (match("sqrt"))
            result = sqrt(parseFactor());
        else if (isdigit(peek()) || peek() == '.')
        {
            result = parseNumber();
        }

        if (peek() == '^')
        {
            get();
            double exponent = parseFactor();
            result = pow(result, exponent);
        }

        return result;
    }

    double parseTerm()
    {
        double result = parseFactor();
        while (peek() == '*' || peek() == '/')
        {
            char op = get();
            double nextFactor = parseFactor();
            if (op == '*')
                result *= nextFactor;
            else
            {
                if (abs(nextFactor) < 1e-9)
                    return 0;
                result /= nextFactor;
            }
        }
        return result;
    }

    double parseExpression()
    {
        double result = parseTerm();
        while (peek() == '+' || peek() == '-')
        {
            char op = get();
            double nextTerm = parseTerm();
            if (op == '+')
                result += nextTerm;
            else
                result -= nextTerm;
        }
        return result;
    }

public:
    ExpressionParser(string s, double val)
    {
        expr = s;
        pos = 0;
        variableValue = val;
    }

    double solve()
    {
        return parseExpression();
    }
};

double evaluateFunction(string s, double n)
{
    ExpressionParser parser(s, n);
    return parser.solve();
}

void Bisection(string s, double low, double high, double error)
{
    double f_low = evaluateFunction(s, low);
    double f_high = evaluateFunction(s, high);

    if (f_low * f_high >= 0)
    {
        cout << "Wrong assumption" << endl;
        return;
    }

    cout << "\n Bisection Method " << endl;
    cout << left << setw(10) << "Iter"
         << setw(15) << "xl"
         << setw(15) << "xu"
         << setw(15) << "xr"
         << setw(15) << "ea (%)" << endl;

    double c = 0, old_c = 0;
    double apperror = 100.0;
    int iteration = 1;
    int max_iter = 1000;

    while (apperror >= error)
    {
        old_c = c;
        c = (low + high) / 2.0;

        if (iteration > 1 && c != 0)
        {
            apperror = abs((c - old_c) / c) * 100.0;
        }
        cout << fixed << setprecision(5);
        cout << left << setw(10) << iteration
             << setw(15) << low
             << setw(15) << high
             << setw(15) << c
             << setw(15) << apperror << endl;

        double f_mid = evaluateFunction(s, c);
        f_low = evaluateFunction(s, low);

        if (abs(f_mid) < 1e-9)
            break;

        if (f_low * f_mid < 0)
            high = c;
        else
            low = c;
        iteration++;
    }
    cout << "Approximate Root: " << c << endl;
}

void FalsePosition(string s, double low, double high, double error)
{
    double f_low = evaluateFunction(s, low);
    double f_high = evaluateFunction(s, high);
    if (f_low * f_high >= 0)
    {
        cout << "Wrong assumption" << endl;
        return;
    }
    cout << "\n False Position Method " << endl;
    cout << left << setw(10) << "Iter"
         << setw(15) << "xl"
         << setw(15) << "xu"
         << setw(15) << "xr"
         << setw(15) << "ea (%)" << endl;
    double c = 0, old_c = 0;
    double apperror = 100.0;
    int iteration = 1;
    int max_iter = 1000;
    while (apperror >= error)
    {
        old_c = c;
        f_low = evaluateFunction(s, low);
        f_high = evaluateFunction(s, high);

        c = (low * f_high - high * f_low) / (f_high - f_low);

        if (iteration > 1 && c != 0)
        {
            apperror = abs((c - old_c) / c) * 100.0;
        }
        cout << fixed << setprecision(5);
        cout << left << setw(10) << iteration
             << setw(15) << low
             << setw(15) << high
             << setw(15) << c
             << setw(15) << apperror << endl;
        double f_mid = evaluateFunction(s, c);

        if (abs(f_mid) < 1e-9)
            break;

        if (f_low * f_mid < 0)
            high = c;
        else
            low = c;

        iteration++;
    }
    cout << "Approximate Root: " << c << endl;
}

double differentiation(string s, double x)
{
    double f_x_plus_h = evaluateFunction(s, x + h);
    double f_x = evaluateFunction(s, x);
    return (f_x_plus_h - f_x) / (h);
}

void newton_raphsan(string s, double x0, double error)
{
    cout << "\n Newton-Raphson Method " << endl;
    cout << left << setw(10) << "Iter"
         << setw(15) << "x" << setw(15) << "f(x)" << setw(15) << "f'(x)" << setw(15) << "ea (%)" << endl;

    double x = x0;
    double old_x = 0;
    double apperror = 100.0;
    int iteration = 1;
    int max_iter = 1000;

    while (apperror >= error)
    {
        old_x = x;
        double f_x = evaluateFunction(s, x);
        double f_prime_x = differentiation(s, x);

        if (abs(f_prime_x) < 1e-9)
        {
            cout << "Derivative too small." << endl;
            return;
        }

        x = x - f_x / f_prime_x;

        if (iteration > 1 && x != 0)
        {
            apperror = abs((x - old_x) / x) * 100.0;
        }
        cout << fixed << setprecision(5);
        cout << left << setw(10) << iteration
             << setw(15) << x
             << setw(15) << f_x
             << setw(15) << f_prime_x
             << setw(15) << apperror << endl;

        if (abs(f_x) < 1e-9)
            break;

        iteration++;
    }

    cout<< "Approximate Root: " << x << endl;
}

void secant(string s, double x0, double x1, double error)
{
    cout << "\n Secant Method " << endl;
    cout << left << setw(10) << "Iter"
         << setw(15) << "x0"
         << setw(15) << "x1"
         << setw(15) << "f(x0)"
         << setw(15) << "f(x1)"
         << setw(15) << "ea (%)" << endl;

    double old_x = 0;
    double apperror = 100.0;
    int iteration = 1;
    int max_iter = 1000;

    while (apperror >= error)
    {
        old_x = x1;
        double f_x0 = evaluateFunction(s, x0);
        double f_x1 = evaluateFunction(s, x1);

        if (abs(f_x1 - f_x0) < 1e-9)
        {
            cout << "Function values too close." << endl;
            return;
        }

        double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (iteration > 1 && x2 != 0)
        {
            apperror = abs((x2 - old_x) / x2) * 100.0;
        }
        cout << fixed << setprecision(5);
        cout << left << setw(10) << iteration
             << setw(15) << x0
             << setw(15) << x1
             << setw(15) << f_x0
             << setw(15) << f_x1
             << setw(15) << apperror << endl;

        if (abs(f_x1) < 1e-9)
            break;

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    cout<< "Approximate Root: " << x1 << endl;
}
int main()
{
    string s;
    double Xl, Xh, error;
    int choice;
    cout << "Enter equation: ";
    cin >> s;
    cout << "Enter Xl, Xh, and error tolerance: ";
    cin >> Xl >> Xh >> error;
    string cleanS = preprocess(s);

    Bisection(cleanS, Xl, Xh, error);
    cout << endl;
    FalsePosition(cleanS, Xl, Xh, error);
    cout << endl;
    newton_raphsan(cleanS, Xl, error);
    cout<<endl;
    secant(cleanS, Xl, Xh, error);

    return 0;
}

