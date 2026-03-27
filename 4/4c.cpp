#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int cajus = 0;
    int cajueiro;
    while (n--){
        cin >> cajueiro;
        cajus += max(0, cajueiro - 10);
    }
    cout << cajus << "\n";
}