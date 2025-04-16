class Solution {
public:
    int jump(vector<int>& nums) {
        //IT IS GIVEN THAT WE CAN ALWAYS REACH nums[n-1] !!
        int n=nums.size();
        vector<int> dp(n,1e8);
        //dp[i]=minimum number of jumps required to reach i!!
        //see the constraints
        //nums[i] is max 1e3 and n is max 1e4
        dp[0]=0;
        for(int i=0;i<n;i++){
            int max_jump=nums[i];
            if(dp[i]==1e8)continue;//i couldn't be reached
            //but actually above case wouldn't be there, as we are able
            //to reach end, so we should be able to reach all intermediate states
            //also as all jumps from 0 to nums[i] are allowed !!
            for(int j=1;j<=max_jump; j++){
                int idx=i+j;
                if(i+j>=n)break;
                dp[idx]=min(dp[idx],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};