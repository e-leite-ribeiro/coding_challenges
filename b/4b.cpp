#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    unordered_map<int, vector<int>> mp;

    int color;
    int value;
    for (int i = 0; i < n; i++){
        cin >> value >> color;
        mp[color].push_back(value);
    }

    for (auto& [key, value] : mp) {
        for (size_t i = 1; i < value.size(); i++){
            if (value[i - 1] > value[i]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}