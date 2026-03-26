#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<array<ll, 3>> dp(n);

    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

    ll a, b, c;
    for (int i = 1; i < n; i++){
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c;
    }

    cout << max({dp[n -1][0], dp[n -1][1], dp[n -1][2]}) << "\n";
}