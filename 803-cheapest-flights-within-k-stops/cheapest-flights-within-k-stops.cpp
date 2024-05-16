class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
        }
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int node=q.front().second.first;
            int st=q.front().first;
            int d=q.front().second.second;
            q.pop();
            if(st>k)continue;
            for(auto it:adj[node]){
                int v=it.first,c=it.second;
                if(d+c<dist[v]&&st<=k){
                    dist[v]=d+c;
                    q.push({st+1,{v,d+c}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
        
    }
};