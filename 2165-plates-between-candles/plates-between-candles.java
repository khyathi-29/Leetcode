class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        List<Integer> candles = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '|') {
                candles.add(i);
            }
        }

        int[] ans = new int[queries.length];
        int j = 0;

        for (int[] q : queries) {
            int[] left = getLeft(candles, q[0]);
            int[] right = getRight(candles, q[1]);

            if (left[0] == -1 || right[0] == -1 || left[0] >= right[0]) {
                ans[j++] = 0;
            } else {
                int totalLength = right[1] - left[1] - 1;
                int candleCount = right[0] - left[0] - 1;
                ans[j++] = totalLength - candleCount;
            }
        }

        return ans;
    }

    // Returns [index in list, value in s] of first candle >= target
    private int[] getLeft(List<Integer> candles, int target) {
        int l = 0, h = candles.size() - 1;
        int ansIdx = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (candles.get(mid) >= target) {
                ansIdx = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (ansIdx == -1) ? new int[]{-1, -1} : new int[]{ansIdx, candles.get(ansIdx)};
    }

    // Returns [index in list, value in s] of last candle <= target
    private int[] getRight(List<Integer> candles, int target) {
        int l = 0, h = candles.size() - 1;
        int ansIdx = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (candles.get(mid) <= target) {
                ansIdx = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return (ansIdx == -1) ? new int[]{-1, -1} : new int[]{ansIdx, candles.get(ansIdx)};
    }
}
