class Solution {
    public boolean hasDuplicate(int[] nums) {
        int n=nums.length;
        int duplicate=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    duplicate = 1;
                    break;
                }
                
            }
            //if(duplicate == 1) break;
        }
        return duplicate == 1;
        
    }
}