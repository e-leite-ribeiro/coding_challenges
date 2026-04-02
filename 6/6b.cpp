#include <bits/stdc++.h>
using namespace std;

string build_path(vector<vector<pair<char, char>>>& labirinth, int x, int y){
    string path = "";

    while (labirinth[x][y].second != 'S'){
        char move = labirinth[x][y].second;
        path.push_back(move);
        switch (move){
            case 'U':
                x++;
                break;
            case 'D':
                x--;
                break;
            case 'L':
                y++;
                break;
            case 'R':
                y--;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<char, char>>> labirinth(N, vector<pair<char, char>>(M));
    pair <int, int> begin, end;
    char block;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> block;
            labirinth[i][j].first = block;
            labirinth[i][j].second = 'S';
            if (labirinth[i][j].first == 'A'){
                begin.first = i;
                begin.second = j;
            }
            if (labirinth[i][j].first == 'B'){
                end.first = i;
                end.second = j;
                labirinth[i][j].first = '.';
            }
        }
    }

    queue <pair <int, int>> positions;
    positions.push(begin);

    while (!positions.empty()){
        pair <int, int> position = positions.front();
        positions.pop();

        if (position.first == end.first && position.second == end.second){
            cout << "YES\n";
            string path = build_path(labirinth, end.first, end.second);
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        if (position.first - 1 >= 0 && labirinth[position.first - 1][position.second].first == '.'){
            labirinth[position.first - 1][position.second].first = 'x';
            labirinth[position.first - 1][position.second].second = 'U';
            positions.push({position.first - 1, position.second});
        }
        if (position.first + 1 < N && labirinth[position.first + 1][position.second].first == '.'){
            labirinth[position.first + 1][position.second].first = 'x';
            labirinth[position.first + 1][position.second].second = 'D';
            positions.push({position.first + 1, position.second});
        }
        if (position.second - 1 >= 0 && labirinth[position.first][position.second - 1].first == '.'){
            labirinth[position.first][position.second - 1].first = 'x';
            labirinth[position.first][position.second - 1].second = 'L';
            positions.push({position.first, position.second - 1});
        }
        if (position.second + 1 < M && labirinth[position.first][position.second + 1].first == '.'){
            labirinth[position.first][position.second + 1].first = 'x';
            labirinth[position.first][position.second + 1].second = 'R';
            positions.push({position.first, position.second + 1});
        }
    }
    cout << "NO\n";
}