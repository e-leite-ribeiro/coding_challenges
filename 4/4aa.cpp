#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n_participants, n_on_time;
    cin >> n_participants >> n_on_time;

    vector<int> participants (n_participants);
    for (int i = 0; i < n_participants; i++){
        cin >> participants[i];
    }

    vector <int> vals = participants;
    sort(vals.begin(), vals. end());
    
    auto get_id = [&](int x){
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    vector <int> bit(vals.size() + 1, 0);

    auto add = [&](int idx, int value){
        while (idx < (int)bit.size()){
            bit[idx] += value;
            idx += idx & -idx;
        }
    };

    auto sum = [&](int idx) {
        int res = 0;
        while (idx > 0){
            res += bit[idx];
            idx -= idx & - idx;
        }
        return res;
    };

    ll n_apologies = 0;
    for (int i = 0; i < n_participants; i++){
        int id = get_id(participants[i]);
        
        if (i >= n_on_time) {
            int seen = i;
            int not_greater = sum(id);
            n_apologies += seen - not_greater;
        }
        add(id, 1);
    }
    cout << n_apologies << "\n";
}