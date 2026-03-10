#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector <int> v;
    int e;
    for (int i = 0; i < n; i++){
        cin >> e;
        v.push_back(e);
    }

    sort(v.begin(), v.end());
    int maxPossible = n / 2;
    int maxTime = v[maxPossible] - v[maxPossible - 1];

    cout << maxPossible << " " << maxTime << "\n";
}