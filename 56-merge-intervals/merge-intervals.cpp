class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int> temp=ans.back();
            int prev_start=temp[0];
            int prev_end=temp[1];
            //if no overlap, push back the pair, else update the pair
            if(intervals[i][0]<=prev_end){
                ans.pop_back();
                temp[1]=max(temp[1],intervals[i][1]);
                ans.push_back(temp);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};