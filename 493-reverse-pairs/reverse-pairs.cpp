// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// typedef tree<int, __gnu_pbds::null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// find_by_order, order_of_key 
//in pbds,if we use less_equal, then it will store duplicates also,just a comparater function

//uper part is for including pbds
typedef long long ll;
class Solution {
public:

void mergesort(vector<int>& a,int n, int left, int right,int &ans){
    //base case
    if(left>=right){
        return;
    }
    int mid=(left+right)>>1;
    mergesort(a,n,left,mid,ans);
    mergesort(a,n,mid+1,right,ans);
    vector<int> temp;
    int i=left,j=mid+1;
    for(int i=left;i<=mid;i++){
        while(j<=right && (ll)a[i]>(ll)2*a[j]){
            j++;
        }
        ans+=j-(mid+1);
    }

    i=left,j=mid+1;//again initializing for merging
    while(i<=mid && j<=right){
        if(a[i]<=a[j]){
            temp.push_back(a[i++]);
        }
        else{
            temp.push_back(a[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=right){
        temp.push_back(a[j++]);
    }
    //now update the vector!!
    for(int k=left;k<=right;k++){
        a[k]=temp[k-left];
    }
    return;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        //from going from left to right, we can maintain the nums[i] in the sorted order
        //and in log n, calculate the number of values greater than nums[j]
        //can use pbds for it
        // pbds P;

        //pbds isn't supported by leetcode, doing using multiset

        // ll ans=0;
        // multiset<ll> P;
        // P.insert(nums[0]);
        // for(int i=1;i<n;i++){
        //     ll greater_count= distance(P.upper_bound((ll)2*nums[i]),P.end());
        //     ans+=greater_count;
        //     P.insert(nums[i]);
        // }
        // return ans;

        //NON PBDS SOLUTION IN THE FOLLOWING
        int ans=0;
        mergesort(nums,n,0,n-1,ans);
        return ans;
    }
};