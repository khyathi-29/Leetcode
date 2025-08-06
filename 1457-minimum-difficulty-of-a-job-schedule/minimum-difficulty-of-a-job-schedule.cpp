class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // If there are fewer jobs than days, it's impossible to schedule
        if (n < d) return -1;

        // dp[i][j] = minimum total difficulty to schedule jobs from index i to end in j days
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));

        // Base case: no jobs left and 0 days left ⇒ 0 difficulty
        dp[n][0] = 0;

        // Loop over number of days from 1 to d
        for (int day = 1; day <= d; day++) {

            // Loop over all possible starting indices for this day
            // i can go from 0 up to n - day (must leave at least one job for each remaining day)
            for (int i = 0; i <= n - day; i++) {

                int maxDifficulty = 0;

                // Try every possible split of the day: assign jobs i to j for today
                // and rest of the jobs from j+1 onward for remaining (day - 1) days
                for (int j = i; j <= n - day; j++) {
                    // Track the hardest job today (day's difficulty = max job)
                    maxDifficulty = max(maxDifficulty, jobDifficulty[j]);

                    // Update dp[i][day] by considering:
                    // - maxDifficulty for jobs i..j today
                    // - dp[j+1][day-1] → min difficulty for the rest of the jobs
                    dp[i][day] = min(dp[i][day], maxDifficulty + dp[j + 1][day - 1]);
                }
            }
        }

        // Final result: minimum total difficulty to schedule all jobs from 0 to n-1 in d days
        return dp[0][d]; 
    }
};