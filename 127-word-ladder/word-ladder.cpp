class Solution {
public:

int differ_by(string a, string b){
    int n=a.length();
    int res=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i])continue;
        res++;
    }
    return res;
}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        //make an undirected edge from i to j if string i and string j differ by 1 character
        //we would find our target node i.e. string =endWord , 
        //we could do multi-source bfs from all the nodes who differ 1 from beginWord
        //and hence find the min distance to the target node
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(differ_by(wordList[i],wordList[j])==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        queue<int> q;
        vector<int> dist(n,1e8);
        for(int i=0;i<n;i++){
            int x=differ_by(wordList[i],beginWord);
            if(x==0){
                dist[i]=0;//beginWord was present in the list, no need to push it
            }
            if(x==1){
                dist[i]=1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dist[v]<1e8)continue; //already visited;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
        //find the target node
        bool present=false;
        int target=-1;
        for(int i=0;i<n;i++){
            //all strings are unique, so no multiple occurencees !!
            if(endWord== wordList[i]){
                target=i;
                present =true;
                break;
            }
        }
        // for(auto it:dist){
        //     cout<<it<<" ";
        // }
        //why +1 ? because i calulated distance i.e. edges, we need to return nodes
        //in the path i.e. edges +1 , !! 
        return (present && dist[target]<1e8)? dist[target]+1 : 0;
    }
};