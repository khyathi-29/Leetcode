class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = 0;
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            totalSum += num;
            freqMap[num] += 1;
        }

        int maxOutlier = INT_MIN;
        for (int num : nums) {
           int requiredSum = totalSum - num;
            if (requiredSum % 2 != 0) continue;

            int potentialSum = requiredSum / 2;
            freqMap[num] -= 1;
            if(freqMap.find(potentialSum)!=freqMap.end() && freqMap[potentialSum]>0)      {                  maxOutlier = max(maxOutlier, num);
            }
            freqMap[num] += 1;
        }

        return maxOutlier;
    }
};