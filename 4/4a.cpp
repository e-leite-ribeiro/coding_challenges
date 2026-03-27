#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, breads, patties, chickens, priceCheddar, priceChicken;
    cin >> n;

    int profit;
    while (n--){
        cin >> breads >> patties >> chickens >> priceCheddar >> priceChicken;
        profit = 0;
        if (priceCheddar > priceChicken){
            profit += priceCheddar * min(breads / 2, patties);
            breads -= patties * 2;
            if (breads > 1){
                profit += priceChicken * min(breads / 2, chickens);
            }
        }
        else{
            profit += priceChicken * min(breads / 2, chickens);
            breads -= chickens * 2;
            if (breads > 1){
                profit += priceCheddar * min(breads / 2, patties);
            }
        }
        cout << profit << "\n";
    }
}