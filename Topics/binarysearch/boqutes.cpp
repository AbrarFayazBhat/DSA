#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Checks if at least m bouquets can be made
    by the given day using adjacent flowers.
    */
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        // This counts bloomed flowers that are adjacent so far.
        int consecutive = 0;

        // This counts how many complete bouquets are already formed.
        int bouquets = 0;

        for (int bloom : bloomDay) {
            // This flower can be used because it has bloomed by the chosen day.
            if (bloom <= day) {
                consecutive++;

                // k adjacent bloomed flowers complete one bouquet.
                if (consecutive == k) {
                    bouquets++;

                    // Reset because these flowers are already used
                    // in the bouquet that was just made.
                    consecutive = 0;
                }
            } else {
                // An unbloomed flower breaks the adjacent group,
                // so the current consecutive count must restart.
                consecutive = 0;
            }
        }

        // The chosen day works only if enough bouquets were formed.
        return bouquets >= m;
    }

    /*
    Returns the minimum day needed to make
    m bouquets from adjacent bloomed flowers.
    */
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = (int)bloomDay.size();

        // If total required flowers are more than available flowers,
        // making all bouquets is impossible.
        if ((long long)m * k > n) {
            return -1;
        }

        // The answer cannot be smaller than the earliest bloom day.
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());

        // The answer never needs to go beyond the latest bloom day.
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minDay; day <= maxDay; day++) {
            // The first working day is the minimum because
            // days are checked in increasing order.
            if (canMakeBouquets(bloomDay, day, m, k)) {
                return day;
            }
        }

        return -1;
    }
};

// Driver code starts
int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    Solution obj;
    cout << obj.minDays(bloomDay, m, k) << endl;

    return 0;
}