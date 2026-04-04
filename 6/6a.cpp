#include <bits/stdc++.h>
using namespace std;

int check_visited(vector <bool>& visited){
    for (int i = 0; i < (int) visited.size(); i++){
        if (!visited[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> friendships (n);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        friendships[a].push_back(b);
        friendships[b].push_back(a);
    }

    vector <bool> visited (n, false);

    int parties = 0;
    int idx = check_visited(visited);
    while (idx != -1){
        queue <int> q;
        q.push(idx);
        visited[idx] = true;
        while (!q.empty()){
            int current = q.front();
            q.pop();
            for (int neighbor : friendships[current]){
                if (!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }

        }
        parties++;
        idx = check_visited(visited);
    }
    cout << parties << "\n";
}