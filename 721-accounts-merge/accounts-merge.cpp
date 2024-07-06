class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        DisjointSet ds(n);
        sort(acc.begin(),acc.end());
        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string word=acc[i][j];
                if(mp.find(word)==mp.end()){
                    mp[word]=i;
                }
                else{
                    ds.unionBySize(i,mp[word]);
                }
            }
        }

        vector<string>mail[n];
        for(auto it:mp){
            string word =it.first;
            int node=ds.findUPar(it.second);
            mail[node].push_back(word);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if (mail[i].size()==0)continue;
            sort(mail[i].begin(),mail[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for (auto it:mail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};