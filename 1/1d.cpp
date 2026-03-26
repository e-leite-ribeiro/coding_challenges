#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int element;
    cin >> element;
    int nextElement;
    ll moves = 0;
    for (int i = 1; i < n; i++){
        cin >> nextElement;

        if (element > nextElement){
            moves += element - nextElement;
            nextElement = element;
        }
        element = nextElement;
    }
    cout << moves << "\n";
}