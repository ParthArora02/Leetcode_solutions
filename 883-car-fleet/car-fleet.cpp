typedef long double ld;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,ld>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=position[i];//position
            v[i].second=(ld)(target-position[i])/(ld)speed[i];//time
        }
        sort(v.begin(),v.end());
        // for(auto &it:v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        stack<ld> st;
        for(int i=0;i<n;i++){
            ld curr_time=v[i].second; //time is second !! first is position
            while(!st.empty() && st.top()<=curr_time){
                st.pop();
            }
            st.push(curr_time);
        }
        int ans=st.size();
        return ans;

    }
};