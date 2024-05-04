class Solution {
    private:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it,adj,vis);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;    
    }
};