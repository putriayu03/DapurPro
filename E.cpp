#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string summarizeNumbers(vector<int>& numbers) {
    int n = numbers.size();
    vector<pair<int, int>> ranges;

    // Urutkan bilangan
    sort(numbers.begin(), numbers.end());

    int left = numbers[0], right = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] == right || numbers[i] == right + 1) {
            // Jika bilangan berurutan atau sama dengan sebelumnya, perpanjang range
            right = numbers[i];
        } else {
            // Jika tidak berurutan, tambahkan range sebelumnya ke hasil dan buat range baru
            ranges.push_back(make_pair(left, right));
            left = numbers[i];
            right = numbers[i];
        }
    }

    // Tambahkan range terakhir ke hasil
    ranges.push_back(make_pair(left, right));

    // Membuat string hasil
    string result = "";
    for (int i = 0; i < ranges.size(); i++) {
        if (i > 0) {
            result += ",";
        }
        if (ranges[i].first == ranges[i].second) {
            result += to_string(ranges[i].first);
        } else {
            result += to_string(ranges[i].first) + "-" + to_string(ranges[i].second);
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    string summary = summarizeNumbers(numbers);
    cout << summary << endl;

    return 0;
}
