#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string word;
    cin >> word;
    int freq[26] = {};
    int n = word.size();
    bool hasSolution = true;
    
    for (int i = 0; i < n; ++i){
        freq[ word[i] - 'A']++;
    }
        
    int oddIndex = -1;
    for (int i = 0; i < 26; ++i){
        if (oddIndex == -1 && freq[i] % 2 == 1){
            oddIndex = i;
        }
        else if (oddIndex != -1 && freq[i] % 2 == 1){
            hasSolution = false;
            break;
        }
    }
    
    if (hasSolution){
        string leftHalf;
        for (int i = 0; i < 26; i++){
            if (freq[i] > 0 && i != oddIndex){
                leftHalf.append(freq[i] / 2, static_cast<char>('A' + i));
            }
        }
        string rightHalf;
        for (int i = 25; i >= 0; i--){
            if (freq[i] > 0 && i != oddIndex){
                rightHalf.append(freq[i] / 2, static_cast<char>('A' + i));
            }
        }
        string middle;
        if (oddIndex != -1){
            middle.assign(freq[oddIndex], static_cast<char>('A' + oddIndex));
        }
        string result = leftHalf + middle + rightHalf;
        cout << result << "\n";
    }
    else {
        cout << "NO SOLUTION\n";
    }
}