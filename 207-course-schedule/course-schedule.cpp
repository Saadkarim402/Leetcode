class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        queue<int>q;
        int ind[n];

        vector<int>adj[n];
        for(int i=0;i<n;i++)ind[i]=0;

        for(auto it:v){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            ind[it]++;
        }
        }
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(q.front());
            q.pop();
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }
        if(ans.size()==n)return true;
        return false;   
    }
};