class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        // Sort each device
        for (auto &row : units)
            sort(row.begin(), row.end());

        // Sort devices by second smallest (or first if only one element)
        sort(units.begin(), units.end(),
             [](vector<int> &a, vector<int> &b) {
                 int x = (a.size() > 1) ? a[1] : a[0];
                 int y = (b.size() > 1) ? b[1] : b[0];
                 return x < y;
             });

        long long ans = 0;
        int smallestRemoved = INT_MAX;

        // Process all devices except the first
        for (int i = 1; i < units.size(); i++) {

            if (units[i].size() == 1) {
                ans += units[i][0];
            } else {
                ans += units[i][1];
                smallestRemoved = min(smallestRemoved, units[i][0]);
            }
        }

        // Rating of the first device after receiving all removed units
        ans += min(units[0][0], smallestRemoved);

        return ans;
    }
};
