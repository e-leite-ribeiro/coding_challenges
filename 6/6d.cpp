#include <bits/stdc++.h>
using namespace std;

int diameter = 0;
int dfs(vector <vector<int>>& tree, int u, int parent){
    int best1 = 0;
    int best2 = 0;
    
    for (int v: tree[u]){
        if(v == parent){
            continue;
        }

        int h = dfs(tree, v, u) + 1;
        if (h > best1){
            best2 = best1;
            best1 = h;
        }
        else if (h > best2){
            best2 = h;
        }
    }
    diameter = max(diameter, best1 + best2);
    return best1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector <vector<int>> tree (N);
    vector <int> heights (N, -1);
    int a, b;
    for (int i = 1; i < N; i++){
        cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(tree, 0, -1);
    cout << diameter << "\n";
}

