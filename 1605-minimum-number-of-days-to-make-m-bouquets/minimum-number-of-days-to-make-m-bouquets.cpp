typedef long long ll;

class Solution {
public:

bool helper(ll mid, vector<int>& v, int m, int k){
    int n=v.size();
    int count =0;
    int counter=0;
    for(int i=0;i<n;i++){
        if(v[i]>mid){
            counter=0;
            continue;
        }
        //else v[i]<=mid obviously
        counter++;
        if(counter==k){
            count++;
            counter=0;
        }
        if(count>=m)return true;
    }
    return count>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n=bloomDay.size();
        if((ll)m*k>(ll)n)return -1;//not possible as no. of flowers required is more
        //than n(available flowers)
        //to make one boquet we need k consecutive flowers!!
        ll l=1,r=1e9;//min value is 1 for a flower to bloom
        ll mid;
        ll ans=1e9+2;//
        while(l<=r){
            mid=(l+r)>>1;
            if(helper(mid,bloomDay,m,k)){
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