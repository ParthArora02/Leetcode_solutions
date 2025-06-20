class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e8));
        //base cases
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        //dp[i][j] state is min to reach from 0,0 to i,j
        //dp[i][j]= min (dp[i-1][j], dp[i][j-1]) + grid[i][j]
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]+=grid[i][j];
            }
        }
        // cout<<dp[i][j
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n-1][m-1];
    }
};