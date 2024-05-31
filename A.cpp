#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> volumes(N);
    int totalVolume = 0;
    for (int i = 0; i < N; i++) {
        cin >> volumes[i];
        totalVolume += volumes[i];
    }

    int avgVolume = totalVolume / N;

    // Cek apakah volume setiap es kopi boba sudah sama semua
    bool isSameVolume = true;
    for (int volume : volumes) {
        if (volume != avgVolume) {
            isSameVolume = false;
            break;
        }
    }

    if (isSameVolume) {
        cout << "SESUAI" << endl;
    } else {
        // Cek apakah memungkinkan untuk menuangkan dari satu gelas ke gelas lain
        vector<int> diff(N);
        for (int i = 0; i < N; i++) {
            diff[i] = volumes[i] - avgVolume;
        }

        bool canPourOnce = false;
        int from, to;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (diff[i] + diff[j] == 0) {
                    canPourOnce = true;
                    from = i + 1;
                    to = j + 1;
                    break;
                }
            }
            if (canPourOnce) {
                break;
            }
        }

        if (canPourOnce) {
            cout << abs(diff[from - 1]) << " " << from << " " << to << endl;
        } else {
            cout << "TIDAK SESUAI" << endl;
        }
    }

    return 0;
}
