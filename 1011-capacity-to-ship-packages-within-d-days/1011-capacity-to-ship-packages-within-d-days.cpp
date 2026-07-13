class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());   // Minimum possible capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum possible capacity
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Candidate capacity

            if (canShip(weights, days, mid)) {
                ans = mid;        // Valid capacity, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;    // Too small, increase capacity
            }
        }
        return ans;
    }

private:
    bool canShip(vector<int>& weights, int days, int cap) {
        int d = 1;   // Start with day 1
        int curr = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (curr + weights[i] > cap) {
                d++;              // Need another day
                curr = weights[i];
            } else {
                curr += weights[i];
            }
        }
        return d <= days;
    }
};