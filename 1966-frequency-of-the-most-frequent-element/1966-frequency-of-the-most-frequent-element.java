class Solution {
    public int maxFrequency(int[] nums, int k) {
        long[] prefixSum = new long[nums.length];
        Arrays.sort(nums);
        prefixSum[0] = nums[0];

        for(int i = 1; i<nums.length; ++i){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        } 
        int p1 = 0;
        int p2 = 1;
        int len = 1;
        while(p1<nums.length && p2<nums.length){
            long requiredSum = nums[p2]*(p2-p1+1);
            long CurrentSum = prefixSum[p2] - (p1 ==0? 0: prefixSum[p1-1]);
            if(CurrentSum + k>= requiredSum){
                len = Math.max(len, p2-p1+1);
                p2++;
            }
            else{
                p1++;
            }

        }
        return len;
        
    }
}