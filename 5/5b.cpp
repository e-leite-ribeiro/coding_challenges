#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int coins [] = {1, 5, 10, 25, 50};
    int n;
    int n_max = 0;

    vector <ll> results;
    while (cin >> n){
        n_max = max(n_max, n);
        results.push_back(n);
    }

    vector <ll> values (n_max + 1);
    values[0] = 1;
    for (int coin : coins){
        for (int i = coin; i <= n_max; i++){
            values[i] += values[i - coin];
        }
    }

    for (size_t i = 0; i < results.size(); i++){
        cout << values[results[i]]<< "\n";
    }
}