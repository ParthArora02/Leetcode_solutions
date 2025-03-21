class Solution {
public:

bool valid(int a, int b, int n, int m){
    return a>=0 && a<n && b>=0 && b<m;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //multi source bfs from all the nodes which have 0
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        //no need to maintain a separate visited matrix, if dist=1e8 => not visited
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            int x=u.first;
            int y=u.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(valid(nx,ny,n,m)){
                    if(dist[nx][ny]==1e8){
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dist;
    }
};