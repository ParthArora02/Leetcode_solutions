class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,i+nums[i]);
            if(maxi==i)return false;//at some point, it isn't able to cross
        }
        return true;
    }
};