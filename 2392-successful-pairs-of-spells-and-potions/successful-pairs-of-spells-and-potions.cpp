class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> v=potions;
        sort(v.begin(),v.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            long long x=spells[i];
            long long num= (success+x-1)/(long long)(x);
            int curr= m -(lower_bound(v.begin(),v.end(),num)-v.begin());
            ans[i]=curr;
        }
        return ans;
    }
};