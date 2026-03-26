#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    list <int> stock;
    char command;
    list <int>::iterator it = stock.begin();
    while (n--){
        cin >> command;
        switch (command){
            case 'm':
                int shift;
                cin >> shift;
                advance(it, shift);
                break;
            case 'i':
                int item_n, item_id;
                cin >> item_n >> item_id;
                it = stock.insert(it, item_n, item_id);
                break;
            case 'd':
                it = stock.erase(it);
                break;
            case 'q':
                cout << *it << "\n";
        }
    }
}