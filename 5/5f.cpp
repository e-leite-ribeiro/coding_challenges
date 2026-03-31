#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, I, M, P;
    cin >> N >> I >> M >> P;

    vector<int> C(M);
    for (int i = 0; i < M; i++){
        cin >> C[i];
    }

    vector<int> V(M + 1);
    for (int i = 1; i <= M; i++){
        cin >> V[i];
    }

    const int INF = INT_MAX;

    vector<vector<int>> dp(N + 2, vector<int>(M + 1, INF));
    vector<vector<bool>> change(N + 2, vector<bool>(M + 1, false));

    for (int age = 1; age <= M; age++){
        dp[N + 1][age] = 0;
    }

    for (int year = N; year >= 1; year--){
        for (int age = 1; age <= M; age++) {
            int replace_cost = (P - V[age]) + C[0] + dp[year + 1][1];

            if (age == M) {
                dp[year][age] = replace_cost;
                change[year][age] = true;
            }
            else {
                int keep_cost = C[age] + dp[year + 1][age + 1];

                if (replace_cost <= keep_cost){
                    dp[year][age] = replace_cost;
                    change[year][age] = true;
                }
                else {
                    dp[year][age] = keep_cost;
                }
            }
        }
    }

    cout << dp[1][I] << "\n";
    vector<int> res;
    int age = I;
    for (int year = 1; year <= N; year++){
        if (change[year][age]){
            res.push_back(year);
            age = 1;
        }
        else{
            age++;
        }
    }

    if (res.empty()){
        cout << "0\n";
    }
    else {
        for (int i = 0; i < (int) res.size(); i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}