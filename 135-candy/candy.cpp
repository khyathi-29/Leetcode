class Solution {
public:
    int candy(vector<int>& ratings) {
     // Edge case: If there is only 1 child, return 1 candy
        if (ratings.size() < 2) {
            return ratings.size();
        }

        int count = 1;  // total candies, start by giving the first child 1 candy
        int i = 1;      // pointer to traverse the ratings array
        int n = ratings.size();

        // Traverse all children
        while (i < n) {
            // Case 1: Equal ratings (flat slope)
            // Every child gets exactly 1 candy if equal to previous
            if (ratings[i] == ratings[i - 1]) {
                count += 1;
                i++;
                continue;  // move to next child
            }

            // Case 2: Upward slope (ratings strictly increasing)
            int peak = 1;  // length of the current increasing run, first child in slope has 1 candy
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;          // slope grows by 1
                count += peak;   // give current child "peak" candies
                i++;
            }

            // Case 3: Downward slope (ratings strictly decreasing)
            int down = 1;  // length of current decreasing run, first child in slope gets 1 candy
            while (i < n && ratings[i] < ratings[i - 1]) {
                count += down;  // give "down" candies to child
                down++;
                i++;
            }

            // Adjust for peak:
            // If downhill run is longer than the uphill run,
            // the peak child needs extra candies to remain strictly higher than downhill neighbors.
            if (down > peak) count += (down - peak);
        }

        return count;  // return the total candies distributed
    }
};