#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, pencils, size;
    cin >> n >> pencils >> size;

    vector <int> nums (n);
    vector <int> prefixSum (n + 1, 0);
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        prefixSum[i + 1] = nums[i] + prefixSum[i];
    }

    const int INF = 1e9;
    vector< vector<int>> dp(n + 1, vector<int>(pencils + 1, INF));
    for (int i = 0; i <=n; i++){
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int k = 0; k <= pencils; k++){
            dp[i][k] = dp[i - 1][k];

            if (k > 0 && i >= size && dp[i - size][k - 1] != INF){
                int blockSum = prefixSum[i] - prefixSum[i - size];
                dp[i][k] = min(dp[i][k], dp[i - size][k - 1] + blockSum);
            }
        }
    }

    int totalSum = prefixSum[n];
    cout << totalSum - dp[n][pencils] << "\n";
}