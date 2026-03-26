#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector <int> domain (n);
    for (int i = 0; i < n; i++){
        cin >> domain[i];
    }

    unordered_map<ll, ll> leftSide;
    for (ll a: domain){
        for( ll b: domain){
            for ( ll c: domain){
                ll x = a * b + c;
                leftSide[x]++;
            }
        }
    }

    unordered_map<ll, ll> rightSide;
    for (ll d: domain){
        if (d != 0){
            for( ll e: domain){
                for ( ll f: domain){
                    ll x = d * (e + f);
                    rightSide[x]++;
                }
            }
        }
    }
    ll nSolutions = 0;

    for (auto &[x, leftCount] : leftSide){
        nSolutions += leftCount * rightSide[x];
    }
    cout << nSolutions << "\n";
}