#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string a;
    string b;

    cin >> n;
    while (n){
        cin >> a;

        cin >> b;

        int lastDigitA = a.back() - '0';
        int lastDigitB = b.back() - '0';
        if ((lastDigitA + lastDigitB) % 2 == 0){
            cout << "PARCEIROS\n";
        }
        else{
            cout << "NAO PARCEIROS\n";
        }
        n--;
    }
}