#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    stack< pair<int, char>> towers;

    int n;
    cin >> n;

    pair<int, char> tower;
    while (n--){
        cin >> tower.first >> tower.second;

        if (!towers.empty() && (tower.first > towers.top().first || (tower.first == towers.top().first && tower.second == towers.top().second))){
            break;
        }
        else if (!towers.empty() && tower.first == towers.top().first && tower.second == 'O' && towers.top().second == 'L'){
            towers.pop();
        }
        else{
            towers.push(tower);
        }
    }

    if (towers.empty()){
        cout << "S" << "\n";
    }
    else {
        cout << "N" << "\n";
    }
}