#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    multiset <int> tickets; 
    int ticket;
    for (int i = 0; i < n; i++){
        cin >> ticket;
        tickets.insert(ticket);
    }

    int fan;
    for (int i = 0; i < m; i++){
        cin >> fan;
        auto pos = tickets.upper_bound(fan);

        if (pos == tickets.begin()){
            cout << -1 << "\n";
        }
        else {
            --pos;
            cout << *pos << "\n";
            tickets.erase(pos);
        }
    }
}