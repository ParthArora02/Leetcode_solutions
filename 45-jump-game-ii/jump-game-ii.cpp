class Solution {
public:
    int jump(vector<int>& nums) {
        //strivers solution https://www.youtube.com/watch?v=7SBVnw7GSTk
        //greedy solution 
        int n=nums.size();
        int jumps=0;
        int l=0,r=0,farthest=0;
        //maintaining a range from l to r
        while(r<n-1){
            for(int i=l;i<=r;i++){
                farthest=max(farthest,nums[i]+i);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};