#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector <int> costs (9);
    
    int minCost = n + 1;
    for (int i = 0; i < 9; i++){
        cin >> costs[i];
        minCost = min(minCost, costs[i]);
    }

    int maxDigits = n / minCost;
    string s;
    for (int i = 0; i < maxDigits; i++){
        for (int j = 8; j >= 0; j--){
            if ((n - costs[j] >= 0) && (n - costs[j])/ minCost >= maxDigits - ( (int) s.size() + 1)){
                s.push_back('0' + (j + 1));
                n -= costs[j];
                break;
            }
        }
    }
    cout << s << "\n";
}