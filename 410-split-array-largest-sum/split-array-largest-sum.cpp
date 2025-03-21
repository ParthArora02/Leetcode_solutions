typedef long long ll;

class Solution {
public:

bool helper(ll mid, vector<int>& nums, int k){
    int n=nums.size();
    int count=0;
    ll curr=0;
    for(int i=0;i<n;i++){
        if(curr+nums[i]<=mid){
            curr+=nums[i];
        }
        else{
            count++;
            curr=nums[i];
        }
    }
    count++;
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
        //we need k non empty subarrays
        ll n=nums.size();
        //sanity check
        if(k>n)return -1;
        ll maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(ll)nums[i]);
        }
        if(k==n)return maxi;
        //binary search on answer
        //if with sum<=x is possible, then with sum <=x+1,x+2 ...  are also possible, 
        //so this is the monotonic function, hence can apply binary search
        ll l=maxi,r=1e11;
        ll mid,ans=1e11;
        while(l<=r){
            mid=(l+r)>>1;
            if(helper(mid,nums,k)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return (int)ans;
    }
};