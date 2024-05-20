class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                long long r=dp[i+1][j+1];
                long long d=dp[i+1][j];
                dp[i][j]=min(r,d)+grid[i][j];
            }
        }
        return dp[0][0];

        
    }
};