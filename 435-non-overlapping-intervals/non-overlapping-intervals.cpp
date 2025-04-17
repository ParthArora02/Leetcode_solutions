class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //first sort the vector based on starting indices, and 
        //if the 2nd interval overlaps with the first one, we would remove the
        //one with the larger value of the end time !!(greedy strategy- 
        //because it we are anyways going to remove one of them, so by 
        //removing the one with larger end value would give more space for
        //future intervals and hence we may need to remove less !!)
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        // for(auto &it:intervals){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }

        int prev_start=intervals[0][0];
        int prev_end=intervals[0][1];
        int removed=0;
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<prev_end){//if overlap, equality not considered a overlap !!
                removed++;
                // cout<<"removed interval = "<<"prev_start"<<" "<<max(prev_end,end)<<endl;
                if(end>=prev_end)continue;//removed the ith interval
                else{
                    prev_end=end;
                }
            }
            else{
                //if no overlap, we need to update prev_ values !!
                prev_start=start;
                prev_end=end;
            }
        }
        return removed;
    }
};