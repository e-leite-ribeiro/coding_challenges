#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count_divisible(ll limit, vector<ll>& primes);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll a, b;
    int n;

    cin >> a >>b >> n;

    vector<ll> primes(n);

    for (int i = 0; i < n; i++){
        cin >> primes[i];
    }

    ll total = b - a + 1;
    ll not_primes = count_divisible(b, primes) - count_divisible(a - 1, primes);

    
    cout << total - not_primes << "\n";
}

ll count_divisible(ll limit, vector<ll> & primes){
    int k = primes.size();
    ll count = 0;

    for (int mask = 1; mask < (1 << k); mask++){
        ll prod = 1;
        bool overflow = false;
        int bits = 0;

        for (int i = 0; i < k; i++){
            if (mask & (1 << i)){
                bits++;
                prod *= primes[i];
                if (prod > limit){
                    overflow = true;
                    break;
                }
            }
        }
        if (overflow || prod > limit) continue;

        ll cnt = limit / prod;
        if (bits % 2){
            count += cnt;
        }
        else {
            count -= cnt;
        }
    }
    return count;
}