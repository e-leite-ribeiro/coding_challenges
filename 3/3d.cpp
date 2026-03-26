#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_divisible(ll limit, vector<ll>& primes);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<ll> integers (n);

    for( int i = 0; i < n; i++){
        cin >> integers[i];
    }
    int ans = INT_MAX;

    for (int mask = 0; mask < (1 << (n - 1)); mask++){
        int x = 0;
        int current_or = integers[0];

        for (int i = 0; i < n - 1; i++){
            if (mask & (1 << i)) {
                x ^= current_or;
                current_or = integers[i + 1];
            }
            else{
                current_or |= integers[i + 1];
            }
        }

        x ^= current_or;
        ans = min(ans, x);
    }

    cout << ans << "\n";
}