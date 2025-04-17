class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newv) {
        int n=v.size();
        vector<vector<int>> ans;

        if(n==0){
            ans.push_back(newv);
            return ans;
        }
        bool inserted=false;
        if(newv[1]<v[0][0]){
            ans.push_back(newv);//starting me hi aagya
            inserted=true;
        }
        for(int i=0;i<n;i++){
            int start=v[i][0];
            int end=v[i][1];
            if(end<newv[0] || newv[1]<start){
                //no overlap
                // if(newv[1]<v[i][0]){
                //     ans.push_back(newv);
                //     inserted=true;
                // }
                if(newv[1]<start && !inserted){
                    ans.push_back(newv);
                    inserted=true;
                }
                ans.push_back(v[i]);
                continue;
            }
            else{
                inserted=true;
                int x=min(start,newv[0]);
                int y=max(end,newv[1]);
                while(i+1<n && newv[1]>=v[i+1][0]){
                    y=max(y,v[i+1][1]);
                    i++;
                }
                vector<int> temp={x,y};
                ans.push_back(temp);
            }
        }
        if(!inserted){//comes in last
            ans.push_back(newv);
        }
        return ans;
    }
};