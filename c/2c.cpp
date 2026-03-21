#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> stones(n);
    int total_w = 0;
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        total_w += stones[i];
    }

    int diff = total_w;
    for (int mask = 0; mask < (1 << n); mask++) {
        int subset_sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset_sum += stones[i];
            }
        }
        diff = min(diff, abs(subset_sum - (total_w - subset_sum)));
    }

    cout << diff << "\n";
}
