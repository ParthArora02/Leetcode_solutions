typedef long long ll;
class Solution {
public:

    ll helper(vector<int>& a,vector<int>& b, int n){
        //IMPORTANT, KADANE'S ALGORITHM !!
        ll maxi=0;
        ll start=-1;
        ll curr_sum=0;
        for(int i=0;i<n;i++){
                while(i<n && curr_sum+(ll)b[i]-(ll)a[i]>=0){
                    curr_sum+=b[i]-a[i];
                    maxi=max(maxi,curr_sum);
                    i++;
                }
                maxi=max(maxi,curr_sum);
                curr_sum=0;
        }
        ll sum_a=0;
        for(int i=0;i<n;i++)sum_a+=a[i];
        ll ans=sum_a+maxi;
        return ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        ll sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        ll ans=max(helper(nums1,nums2,n),helper(nums2,nums1,n));
        return (int )ans;
    }
};