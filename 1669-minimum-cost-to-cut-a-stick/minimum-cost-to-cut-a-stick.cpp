class Solution {
    private:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        long long mini=1e9;
        for(int k=i;k<=j;k++){
            long long cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(1,cuts.size()-2,cuts,dp); 
    }
};