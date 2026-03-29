#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, area;
    cin >> n >> area;
    while (n != 0 && area != 0){
        vector <int> strips (n);

        int totalArea = 0;
        int maxHeight = 0;
        for (int i = 0; i < n; i++){
            cin >> strips[i];
            totalArea += strips[i];
            maxHeight = max(maxHeight, strips[i]);
        }

        if (totalArea == area){
            cout << ":D\n";
        }
        else if (totalArea < area){
            cout << "-.-\n";
        }
        else{
            double bottom = 0;
            double top = (double) maxHeight;
            double mid;
            double eps = 0.00001;
            int count = 100;
            while (count--){
                mid = (top + bottom) / 2;
                double areaSum = 0;
                for (int strip : strips){
                    double share = max( (double)0, strip - mid);
                    areaSum += share;
                }
                if (abs(areaSum - area) < eps){
                    break;
                }
                else if (areaSum > area){
                    bottom = mid;
                }
                else {
                    top = mid;
                }
            }
            cout << fixed << setprecision(4) << mid << "\n";
        }

        cin >> n >> area;
    }
}