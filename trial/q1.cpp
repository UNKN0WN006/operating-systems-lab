
#include <bits/stdc++.h>
using namespace std;

void f(int n, int o, int c, string s, vector<string>& v) {
    if (s.size() == 2 * n) { v.push_back(s); return; }
    if (o < n) f(n, o + 1, c, s + '(', v);
    if (c < o) f(n, o, c + 1, s + ')', v);
}

int main() {
    int n; cin >> n;
    vector<string> v;
    f(n, 0, 0, "", v);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto& s : v) cout << s << '\n';
    return 0;
}
