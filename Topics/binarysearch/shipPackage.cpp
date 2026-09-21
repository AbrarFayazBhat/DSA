#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Counts how many days are needed to ship
    all packages with the given capacity.
    */
    int daysNeeded(vector<int>& weights, int capacity) {
        // At least one day is needed when packages exist.
        int days = 1;

        // This stores the total weight loaded on the current day.
        int currentLoad = 0;

        for (int weight : weights) {
            // Start a new day when the next package
            // would cross the ship capacity.
            if (currentLoad + weight > capacity) {
                days++;

                // The current package becomes the first package
                // loaded on the new day.
                currentLoad = weight;
            } else {
                // The package fits in the current day,
                // so it can be added to the ongoing load.
                currentLoad += weight;
            }
        }

        return days;
    }

    /*
    Returns the minimum ship capacity needed
    to ship all packages within the given days.
    */
    int shipWithinDays(vector<int>& weights, int days) {
        // The ship must at least carry the heaviest package.
        int minCapacity = *max_element(weights.begin(), weights.end());

        // Carrying all packages in one day is always enough.
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        for (int capacity = minCapacity; capacity <= maxCapacity; capacity++) {
            // The first capacity that finishes within days
            // is the minimum because capacities increase by one.
            if (daysNeeded(weights, capacity) <= days) {
                return capacity;
            }
        }

        return -1;
    }
};

// Driver code starts
int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    Solution obj;
    cout << obj.shipWithinDays(weights, days) << endl;

    return 0;
}