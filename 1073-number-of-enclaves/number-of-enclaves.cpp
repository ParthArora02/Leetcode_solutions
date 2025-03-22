class Solution {
public:

bool valid(int a,int b, int n, int m){
    return a>-1 &&a<n && b>-1&& b<m;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //basically a multisource bfs from all the lands at the boundary we have to calculate
        //and subtract them from the total, 
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                visited[i][0]=true;
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                visited[i][m-1]=true;
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                visited[0][i]=true;
            }
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                visited[n-1][i]=true;
            }
        }
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            int x=u.first;
            int y=u.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(valid(nx,ny,n,m) && !visited[nx][ny]){
                    if(grid[nx][ny]==1){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int count=0;
        //our answer is number of 1's which aren't visited!!
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
         return count;  
    }
};