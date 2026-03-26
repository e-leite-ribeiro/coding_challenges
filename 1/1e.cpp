#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && (a == 0 || a == 1)){
        cout << - c << "\n";
    }
    else if (a == 0 && b == 1){
        cout << -1 - c << "\n";
    }
    else {
        cout << a - (b * c) << "\n";
    }
}