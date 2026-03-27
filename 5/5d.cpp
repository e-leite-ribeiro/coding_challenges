#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll calculate_fx(unordered_map <ll, ll>& fx, ll x){
    if (fx.find(x) != fx.end()){
        return fx[x];
    }
    if (fx.find(x / 2) == fx.end()){
        fx[x / 2] = calculate_fx(fx, x / 2);
    }
    if (fx.find(x / 3) == fx.end()){
        fx[x / 3] = calculate_fx(fx, x / 3);
    }
    return fx[x / 2] + fx[x / 3];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    unordered_map<ll, ll> fx;
    fx[0] = 1;
    if (n > 0){
        fx[n] = calculate_fx(fx, n);
    }

    cout << fx[n] << "\n";
}