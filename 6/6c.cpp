#include <bits/stdc++.h>
using namespace std;

void dfs_preOrder(int u, unordered_map <int, vector<int>> & children, vector<int> & pos,
        vector<int> & id_at_pos, int & timer){
    pos[u] = timer;
    id_at_pos[timer] = u;
    timer++;

    auto it = children.find(u);
    if (it == children.end()) return;

    for (int v: it->second) {
        dfs_preOrder(v, children, pos, id_at_pos, timer);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<array<int, 3>> ops;
    ops.reserve(n);
    
    int id_sucessor = 2;
    unordered_map<int, vector<int>> children;
    int command, x;
    for (int i = 0; i < n; i++){
        cin >> command >> x;

        if (command == 1){
            children[x].push_back(id_sucessor);
            ops.push_back({command, x, id_sucessor});
            id_sucessor++;
        }
        else {
            ops.push_back({command, x, -1});
        }
    }

    int V = id_sucessor - 1;

    vector<int> pos (V + 1, - 1), id_at_pos(V);
    int timer = 0;
    dfs_preOrder(1, children, pos, id_at_pos, timer);

    vector<bool> born(V + 1, 0), dead(V + 1, 0);
    born[1] = true;

    set<int> alive_pos;
    alive_pos.insert(pos[1]);

    int king = 1;

    for (auto &op : ops){
        if (op[0] == 1){
            int child = op[2];
            born[child] = true;
            alive_pos.insert(pos[child]);
        }
        else{
            int x = op[1];
            dead[x] = true;
            alive_pos.erase(pos[x]);

            if (x == king){
                king = id_at_pos[*alive_pos.begin()];
            }
            cout << king << "\n";
        }
    }
}