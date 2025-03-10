struct Edge{
    int u,v,weight;
    bool operator<(const Edge&other)const{//for sorting in ascending order
        return weight<other.weight;
    }
};
struct DSU{
    vector<int> parent,rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    bool is_same(int x, int y){
        return find(x)==find(y);
    }
    void unite(int x, int y){
        int rootx=find(x), rooty=find(y);
        if(rootx==rooty)return ;//already joined
        if(rank[rootx]>rank[rooty])parent[rooty]=rootx;
        else if(rank[rootx]<rank[rooty])parent[rootx]=rooty;
        else{
            parent[rootx]=rooty;
            rank[rooty]++;
        }
        return;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //apply kruskal's algo to find MST
        int n=points.size();
        //number of edges=nC2
        int m=n*(n-1);
        m/=2;
        //make an edge between all nodes
        vector<Edge> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i+1,j+1,wt});
            }
        }
        sort(edges.begin(),edges.end());
        long long ans=0;
        DSU dsu(n);
        int count=0;//number of edges formed, when == n-1, would return as the tree is formed
        vector<Edge> mst;
        for(Edge &e: edges){
            int x=e.u, y=e.v, wt=e.weight;
            if(dsu.is_same(x,y))continue;
            dsu.unite(x,y);
            mst.push_back(e);
            ans+=wt;
            count++;
            if(count==n-1)break;
        }
        // cout<<mst.size()<<endl;
        return ans;
    }
};