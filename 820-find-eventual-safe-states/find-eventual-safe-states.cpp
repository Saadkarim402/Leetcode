class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        queue<int>q;
        vector<int>ans;
        int ind[n];
        for(int i=0;i<n;i++)ind[i]=0;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                ind[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;   
    }
};