#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isGeneratorBad(vector<int>& nums, int X, int Y) {
    if (X <= 0) return true;
    if (Y < 0) return false;
    if (nums.empty()) return false;

    sort(nums.begin(), nums.end());
    int maxCount = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int left_bound = nums[i] + 2 * Y;
        int lo = i, hi = n - 1;
        int j = i;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= left_bound) {
                j = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        maxCount = max(maxCount, j - i + 1);
    }
    return maxCount >= X;
}

int main() {
    int n, X, Y;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> X >> Y;

    if (isGeneratorBad(nums, X, Y)) {
        cout << "Generator needs improvement." << endl;
    }
    else {
        cout << "Generator is good." << endl;
    }
    return 0;
}