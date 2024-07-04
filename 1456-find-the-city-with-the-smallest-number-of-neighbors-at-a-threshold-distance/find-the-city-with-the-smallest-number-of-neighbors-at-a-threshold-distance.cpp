class Solution {
    private:
    vector<int>solve(int i,vector<pair<int,int>>adj[],int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        pq.push({0,i});
        dist[i]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second,cost=it.first;
            for(auto it:adj[node]){
                int v=it.first,wt=it.second;
                if(dist[v]>wt+cost){
                    dist[v]=wt+cost;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int cnt_ans=1e9,city;
        for(int i=0;i<n;i++){
            int cnt=0;
            vector<int>dist=solve(i,adj,n);
            for(int j=0;j<n;j++){
                if(j!=i&&dist[j]<=th){
                    cnt++;
                }
            }
            cout<<cnt<<endl;
            if(cnt_ans>=cnt){
                cnt_ans=cnt;
                city=i;
            }
        }
        return city;
    }

};