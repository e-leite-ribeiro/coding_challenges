#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, T;
    cin >> N >> M >> T;
    vector <vector <int>> forest (N, vector <int> (M));
    queue <pair <int, int>> q;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> forest[i][j];

            if (forest[i][j] == 0){
                q.push({i, j});
            }
        }
    }

    vector<vector<int>> fire_4(N, vector<int>(M, 0));
    vector<vector<bool>> scheduled(N, vector<bool>(M, false));

    int dx_4[] = {-1, 1, 0, 0};
    int dy_4[] = {0, 0, -1, 1};
    int dx_8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy_8[] = {-1, 0, 1, -1, 1, -1, 0, 1};


    for (int t = 0; t < T && !q.empty(); t++){
        vector <pair<int, int>> to_burn;

        int size = q.size();
        while (size--){
            auto[x, y] = q.front();
            q.pop();

            for (int k = 0; k < 8; k++){
                int nx = x + dx_8[k];
                int ny = y + dy_8[k];

                if (0 <= nx && nx < N && 0 <= ny && ny < M){
                    if (forest[nx][ny] == 1 && !scheduled[nx][ny]){
                        scheduled[nx][ny] = true;
                        to_burn.push_back({nx, ny});
                    }
                }
            }

            for (int k = 0; k < 4; k++){
                int nx = x + dx_4[k];
                int ny = y + dy_4[k];

                if (0 <= nx && nx < N && 0 <= ny && ny < M){
                    if (2 <= forest[nx][ny] && forest[nx][ny] <= 4 && !scheduled[nx][ny]) {
                        fire_4[nx][ny]++;
                        if(fire_4[nx][ny] >= forest[nx][ny] - 1){
                            scheduled[nx][ny] = true;
                            to_burn.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        for (auto [x, y] : to_burn){
            forest[x][y] = 0;
            q.push({x, y});
        }
    }

    int fires = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (forest[i][j] == 0){
                fires++;
            }
        }
    }
    cout << fires << "\n";
}