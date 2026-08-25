class Solution {
    public int longestConsecutive(int[] nums) {
        int n=nums.length;

        HashSet<Integer> set=new HashSet<>();
        for(int x:nums){
            set.add(x);
        }
        int mLen=0;
        for(int x:nums){
            if(!set.contains(x-1)){
                int current=x;
                int length=1;

                while(set.contains(current+1)){
                    current++;
                    length++;
                }
                mLen=Math.max(mLen,length);
            }
        }
        return mLen;

        
    }
}
