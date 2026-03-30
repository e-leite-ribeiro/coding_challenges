#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n_dishes, n_portions, n_conditions;
    cin >> n_dishes >> n_portions >> n_conditions;

    vector <int> satisfactions(n_dishes);

    for (int i = 0; i < n_dishes; ++i){
        cin >> satisfactions[i];
    }

    vector<vector<int>> conditions(n_dishes, vector<int>(n_dishes, 0));
    int previous_dish, dish, bonus;
    for (int i = 0; i < n_conditions; i++){
        cin >> previous_dish >> dish >> bonus;
        conditions[previous_dish - 1][dish - 1] = bonus;
    }

    int total_configurations = 1 << n_dishes;
    vector<vector<ll>> dp(total_configurations, vector<ll>(n_dishes, -1));


    for (int i = 0; i < n_dishes; ++i){
        dp[1 << i][i] = satisfactions[i];
    }

    ll maxSatisfaction = 0;
    for (int mask = 1; mask < total_configurations; ++mask){
        int used_dishes = __builtin_popcount(mask);
        if (used_dishes > n_portions){
            continue;
        }

        for (int last = 0; last < n_dishes; ++last){
            if (dp[mask][last] == -1){
                continue;
            }

            if (used_dishes == n_portions){
                maxSatisfaction = max(maxSatisfaction, dp[mask][last]);
                continue;
            }

            for (int next = 0; next < n_dishes; next++){
                if (mask & (1 << next)){
                    continue;
                }

                int next_mask = mask | (1 << next);
                ll next_value = dp[mask][last] + satisfactions[next] + conditions[last][next];
                dp[next_mask][next] = max(dp[next_mask][next], next_value);
            }
        }
    }
    cout << maxSatisfaction << "\n"; 
}