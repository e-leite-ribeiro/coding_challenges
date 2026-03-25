#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    int L;
    int n;

    while (T--){
        cin >> L;
        cin >> n;
        int minTime = 0;
        int maxTime = 0;
        int antPos;
        for (int i = 0; i < n; i++){
            cin >> antPos;
            minTime = max(minTime, min(antPos, L - antPos));
            maxTime = max(maxTime, max(antPos, L - antPos));
        }
        cout << minTime << " " << maxTime << "\n";
    }
}