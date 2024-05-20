class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        long long dp[n][m];
        int s=0;
        for(int i=n-1;i>=0;i--){
            s+=grid[i][m-1];
            dp[i][m-1]=s;
        }
        s=0;
        for(int i=m-1;i>=0;i--){
            s+=grid[n-1][i];
            dp[n-1][i]=s;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                long long r=dp[i][j+1];
                long long d=dp[i+1][j];
                dp[i][j]=min(r,d)+grid[i][j];
            }
        }
        return dp[0][0];

        
    }
};