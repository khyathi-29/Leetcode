class Solution {
public:
    int candy(vector<int>& ratings) {
       if (ratings.size() < 2) {
            return ratings.size(); // If only 1 child, give 1 candy
        }

        int count = 1;           // total candies so far (first child gets 1)
        int upSlopeLength = 0;   // length of last upward slope segment
        int upSlope = 0;         // counter for current upward slope
        int downSlope = 0;       // counter for current downward slope

        for (int i = 1; i < ratings.size(); i++) {
            int previous = ratings[i - 1];
            int me = ratings[i];

            // Case 1: Equal ratings
            if (me == previous) {
                upSlope = 0;
                downSlope = 0;
                upSlopeLength = 0;
                count += 1; // each flat kid gets exactly 1 candy
            }
            // Case 2: Upward slope (current rating higher than previous)
            else if (me > previous) {
                upSlope = (upSlope == 0 ? 1 : upSlope) + 1; // extend upSlope
                downSlope = 0;
                count += upSlope; // give 1 more candy than previous child
                upSlopeLength = upSlope; // mark the peak length
            }
            // Case 3: Downward slope (current rating lower than previous)
            else {
                upSlope = 0;
                downSlope += 1;
                // Peak adjustment: if downhill is longer than uphill,
                // the peak child needs 1 extra candy
                int slopeDiff = (downSlope + 1 - upSlopeLength) > 0 ? 1 : 0;
                count += downSlope + slopeDiff;
            }
        }

        return count;
    }
};