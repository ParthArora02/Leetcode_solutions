typedef long long ll;

class Solution {
public:

bool helper(ll mid,vector<int>& weights, int days){
    int count=0;
    ll n=weights.size();
    ll curr=0;
    for(int i=0;i<n;i++){
        if(curr+weights[i]<=mid){
            curr+=weights[i];
        }
        else{
            count++;
            curr=weights[i];
        }
    }
    //don't forget this one ;) when curr!=0 we need to send this too!!
    // if(curr!=0){
        count++;
    // }
    return count<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        ll n=weights.size();
        //we have to deliever all packages, so capacity atleast= max weight
        //upperbound of capacity = sum of all weights i.e. in 1 day
        ll l=0,r=0;
        for(auto &it:weights){
            l=max(l,(ll)it);
            r+=(ll)it;
        }
        // cout<<l<<" "<<r<<endl;
        ll mid;
        ll ans=1e9;
        while(l<=r){
            mid=(l+r)>>1;
            if(helper(mid,weights,days)){
                // cout<<mid<<endl;
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