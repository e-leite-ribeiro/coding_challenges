#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector <string> words (n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }

    sort(words.begin(), words.end(), [](const string & a, const string & b) {
        return a + b < b + a;
    });

    string concatWord = "";
    for (string s: words){
        concatWord.append(s);
    }
    cout << concatWord << "\n";
}