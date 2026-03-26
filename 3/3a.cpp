#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& permutation, vector<vector<int>>& graph, vector<int>& inDegree, vector<bool>& used, int n){
    if (permutation.size() == static_cast<size_t>(n)){
        for (int i = 0; i < n; i++){
            cout << permutation[i] << " ";
        }
        cout << '\n';
    }
    for (int x = 0; x < n; x++){
        if (!used[x] && inDegree[x] == 0){
            used[x] = true;
            permutation.push_back(x + 1);
            for (int y : graph[x]) inDegree[y]--;

            backtrack(permutation, graph, inDegree, used, n);

            for (int y : graph[x]) inDegree[y]++;
            permutation.pop_back();
            used[x] = false;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int nBooks, nConditions;
    cin >> nBooks >> nConditions;
    vector<vector<int>> graph(nBooks);
    vector<int> inDegree(nBooks);
    vector<int> permutation;
    vector<bool> used (nBooks, false);

    int a, b;

    for (int i = 0; i < nConditions; i++){
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        inDegree[b - 1]++;
    }

    backtrack(permutation, graph, inDegree, used, nBooks);
}