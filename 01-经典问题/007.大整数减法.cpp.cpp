#include <bits/stdc++.h>
using namespace std;
string dict = "0123456789";

string sub(string a, string b) {
    string c;
    int t = 0;
    int i = a.size() - 1, j = b.size() - 1;
    int pos = 0;
    while (i >= 0) {
        t = dict.find(a[i]);
        if (j >= 0) t -= dict.find(b[j]);
        if (t < 0) {
            a[i - 1]--;
            t += 10;
        }
        c += dict[t];
        i--;
        j--;
    }
    reverse(c.begin(), c.end());
    while (c[pos] == '0' && pos < c.size() - 1) pos++;
    c.erase(0, pos);
    return c;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << sub(a, b) << endl;
}