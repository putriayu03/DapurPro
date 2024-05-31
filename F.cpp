#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Province {
    string name;
    vector<int> values;
};

int main() {
    int P, N, K;
    cin >> P >> N >> K;

    vector<Province> provinces(P);

    for (int i = 0; i < P; i++) {
        cin.ignore();
        getline(cin, provinces[i].name);
        provinces[i].values.resize(N);
        for (int j = 0; j < N; j++) {
            cin >> provinces[i].values[j];
        }
    }

    string selectedProvince;
    int closestPriceDiff = K;

    for (int i = 0; i < P; i++) {
        int maxSubset = pow(2, N);
        vector<int> subsetSum(maxSubset, 0);

        for (int j = 1; j < maxSubset; j++) {
            for (int k = 0; k < N; k++) {
                if (j & (1 << k)) {
                    subsetSum[j] = subsetSum[j - (1 << k)] + provinces[i].values[k];
                }
            }

            int priceDiff = abs(K - subsetSum[j]);
            if (priceDiff < closestPriceDiff) {
                closestPriceDiff = priceDiff;
                selectedProvince = provinces[i].name;
            }
        }
    }

    cout << selectedProvince << endl;

    return 0;
}
