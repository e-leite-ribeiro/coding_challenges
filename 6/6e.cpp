#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int>> tree;
vector <int> subtree_size;
int centroid = -1;
bool dfs(int u, int parent){
    subtree_size[u] = 1;
    int max_component = 0;
    for (int v : tree[u]){
        if (v == parent) continue;
        if (dfs(v, u)) return true;
        
        subtree_size[u] += subtree_size[v];
        max_component = max(max_component, subtree_size[v]);
    }
    max_component = max(max_component, n - subtree_size[u]);
    if (max_component <= n / 2 && centroid == -1){
        centroid = u;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    tree.assign(n, {});
    subtree_size.assign(n, 0);
    
    int a, b;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    dfs(0, -1);
    cout << centroid + 1 << "\n";
}