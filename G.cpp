#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_keren(int a, int b) {
    int product = a * b;
    int square_root = static_cast<int>(sqrt(product));
    return square_root * square_root == product;
}

int find_smallest_k(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> unique_nums(nums.begin(), nums.end());

    for (int k = 2; k <= n; ++k) {
        bool valid = true;
        for (int i = 0; i <= n - k; ++i) {
            vector<int> subsequence(nums.begin() + i, nums.begin() + i + k);
            if (unique_nums.size() == subsequence.size()) {
                bool is_valid_subseq = true;
                for (int j = 0; j < k; ++j) {
                    for (int l = j + 1; l < k; ++l) {
                        if (!is_keren(subsequence[j], subsequence[l])) {
                            is_valid_subseq = false;
                            break;
                        }
                    }
                    if (!is_valid_subseq) {
                        break;
                    }
                }
                if (is_valid_subseq) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            return k;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = find_smallest_k(nums);
    cout << result << endl;

    return 0;
}
