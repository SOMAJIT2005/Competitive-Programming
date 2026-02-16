#include <bits/stdc++.h>

using namespace std;

string preprocess(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        res += s[i];
        if (i + 1 < s.length()) {
         
            if (isdigit(s[i]) && (s[i+1] == 'x' || isalpha(s[i+1]))) {
                res += '*';
            }
          
            else if (s[i] == ')' && (s[i+1] == 'x' || isdigit(s[i+1]))) {
                res += '*';
            }
        
            else if (s[i] == 'x' && s[i+1] == '(') {
                res += '*';
            }
        }
    }
    return res;
}

class ExpressionParser {
    string expr;
    int pos;
    double variableValue;

    char peek() {
        if (pos < expr.length()) return expr[pos];
        return 0;
    }

    char get() {
        char c = peek();
        if (pos < expr.length()) pos++;
        return c;
    }

    bool match(string funcName) {
        if (expr.substr(pos, funcName.length()) == funcName) {
            pos += funcName.length();
            return true;
        }
        return false;
    }

    double parseNumber() {
        string numStr = "";
        while (isdigit(peek()) || peek() == '.') {
            numStr += get();
        }
        if (numStr.empty()) return 0;
        return stod(numStr);
    }

    double parseFactor() {
        if (peek() == '+') { get(); return parseFactor(); }
        if (peek() == '-') { get(); return -parseFactor(); }

        double result = 0;

        if (peek() == '(') {
            get();
            result = parseExpression();
            if (peek() == ')') get();
        }
        else if (peek() == 'x') {
            get();
            result = variableValue;
        }
    
        else if (match("sin")) result = sin(parseFactor());
        else if (match("cos")) result = cos(parseFactor());
        else if (match("tan")) result = tan(parseFactor());
        else if (match("csc")) result = 1.0 / sin(parseFactor());
        else if (match("sec")) result = 1.0 / cos(parseFactor());
        else if (match("cot")) result = 1.0 / tan(parseFactor());
        else if (match("log")) result = log10(parseFactor()); 
        else if (match("ln"))  result = log(parseFactor());   
        else if (match("sqrt")) result = sqrt(parseFactor());
        else if (isdigit(peek()) || peek() == '.') {
            result = parseNumber();
        }

        if (peek() == '^') {
            get();
            double exponent = parseFactor();
            result = pow(result, exponent);
        }

        return result;
    }

    double parseTerm() {
        double result = parseFactor();
        while (peek() == '*' || peek() == '/') {
            char op = get();
            double nextFactor = parseFactor();
            if (op == '*') result *= nextFactor;
            else {
                if (abs(nextFactor) < 1e-9) return 0;
                result /= nextFactor;
            }
        }
        return result;
    }

    double parseExpression() {
        double result = parseTerm();
        while (peek() == '+' || peek() == '-') {
            char op = get();
            double nextTerm = parseTerm();
            if (op == '+') result += nextTerm;
            else result -= nextTerm;
        }
        return result;
    }

public:
    ExpressionParser(string s, double val) {
        expr = s;
        pos = 0;
        variableValue = val;
    }

    double solve() {
        return parseExpression();
    }
};

double evaluateFunction(string s, double n) {
    ExpressionParser parser(s, n);
    return parser.solve();
}

int main() {
    string s;
    double n;

    cin >> s >> n;

    string cleanS = preprocess(s);


    cout << evaluateFunction(cleanS, n) << endl;

    return 0;
}