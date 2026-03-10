#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    stack <int> lifo;
    queue <int> fifo;
    priority_queue <int> pq;

    int n;
    cin >> n;

    int command;
    int id;

    while(n--){
        cin >> command;
        cin >> id;
        if (command == 0){
            lifo.push(id);
            fifo.push(id);
            pq.push(id);
        }
        else{
            if (lifo.top() == id){
                lifo.pop();
            }
            if (fifo.front() == id){
                fifo.pop();
            }
            if (pq.top() == id){
                pq.pop();
            }
        }
    }

    if ((fifo.empty() && pq.empty()) || (lifo.empty() && pq.empty())){
        cout << "ambiguous" << "\n";
    }
    else if (pq.empty()){
        cout << "priority" << "\n";
    }
    else if (fifo.empty()){
        cout << "fifo" << "\n";
    }
    else if (lifo.empty()){
        cout << "lifo" << "\n";
    }
    else {
        cout << "unknown" << "\n";
    }
}