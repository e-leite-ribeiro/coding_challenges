#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128_t;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector <ll> pg;
    ll elem;
    for (int i = 0; i < n; i++){
        cin >> elem;
        pg.push_back(elem);
    }
    sort(pg.begin(), pg.end());

    vector <ll> ratio = {pg[0], pg[1]};
    if ((lll) pg[2] * ratio[0] != (lll) pg[1] * ratio[1]) {
        if ((lll) pg [3] * ratio[0] == (lll) pg [2] * ratio [1]){
            cout << (ll) ( (lll) pg[2] * ratio [0] / ratio[1] ) << "\n";
            return 0;
        }
        else {
            cout << (ll) ( (lll) pg[0] * pg[2] / pg[1] )<< "\n";
            return 0;
        }
    }
    for (int i = 3; i < n; i++){
        if ((lll) pg[i] * ratio[0] != (lll) pg[i - 1] * ratio[1]){
            cout << (ll) ((lll) pg[i] * ratio[0] / ratio[1]) << "\n";
            return 0;
        }
    }

    if (ratio[0] != ratio[1] && ((lll) pg[0] * ratio[0]) % ratio[1] == 0){
        cout << (ll) ((lll) pg[0] * ratio[0] / ratio[1])  << "\n";
    }
    if (((lll)pg[n - 1] * ratio[1]) % ratio[0] == 0) {
        cout << (ll) ((lll) pg[n - 1] * ratio[1] / ratio[0] ) << "\n";
    }
}