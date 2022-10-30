#include<bits/stdc++.h>
using namespace std;
int p; string s;
int exp();
int factor() {
    int val = 0;
    if (s[p] == '(')
        p++, val = exp(), p++;
    else
        while (isdigit(s[p]))
            val = val * 10 + s[p++] - '0';
    return val;
}
int term() {
    int val = factor();
    while (s[p] == '*' || s[p] == '/')
        if (s[p] == '*')
            p++, val *= factor();
        else
            p++, val /= factor();
    return val;
}
int exp() {
    int val = term();
    while (s[p] == '+' || s[p] == '-')
        if (s[p] == '+')
            p++, val += term();
        else
            p++, val -= term();
    return val;
}
int main() {
    cin >> s; p = 0;
    cout << exp() << endl;
}