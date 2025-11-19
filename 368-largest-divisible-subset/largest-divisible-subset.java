class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] parent = new int[nums.length];
        Arrays.fill(parent,-1);
        int[] size = new int[nums.length];
        Arrays.fill(size,1);
        int ans = 0;
        int index =-1;
        int ansIndex = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(size[j]<size[i]+1){
                        size[j]=size[i]+1;
                        parent[j]=i;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans<size[i]){
                ans = size[i];
                ansIndex = i;
            }
        }
       List<Integer> result = new ArrayList<>();
        int j = ans-1;
        while(ansIndex!=-1){
             result.add(nums[ansIndex]);
             ansIndex = parent[ansIndex];
        }
        Collections.reverse(result);
       return result;
    }
}