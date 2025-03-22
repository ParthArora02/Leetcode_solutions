class Solution {
public:

bool valid(int a, int b, int n, int m){
    return a>-1 && a<n && b>-1 && b<m;
}

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        //only O's which are at the edge and those connecte to these O's would survive
        //so we would do bfs/dfs frome these nodes and mark all O's as visited, 
        //after that every cell except these visited==true cells, would be X 
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){q.push({i,0});visited[i][0]=true;}
            if(board[i][m-1]=='O'){q.push({i,m-1});visited[i][m-1]=true;}
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){q.push({0,i});visited[0][i]=true;}
            if(board[n-1][i]=='O'){q.push({n-1,i});visited[n-1][i]=true;}
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
                if(valid(nx,ny,n,m)){
                    if(!visited[nx][ny] && board[nx][ny]=='O'){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};