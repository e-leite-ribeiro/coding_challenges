#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int size;
    int n_commands;

    cin >> size;
    cin >> n_commands;
    
    string word;
    int pos = 0;
    int command [2];

    cin >> word;
    while (n_commands--){
        cin >> command[0];
        cin >> command[1];

        if (command[0] == 2){
            int shift = (command[1] - 1) % size;
            if (shift < 0) shift += size;
            int index = (pos + shift) % size;
            cout << word[index] << "\n";
        }
        else {
            int rot = command[1] % size;
            pos = (pos - rot);
            if (pos < 0){
                pos = size + pos;
            }
        }
    }
}