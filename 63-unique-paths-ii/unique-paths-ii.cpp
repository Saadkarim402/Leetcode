class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        long long dp[n][m];
        bool f=false;
        for(int i=n-1;i>=0;i--){
            if(f) dp[i][m-1]=0;
            else{
            if(grid[i][m-1]==1){
                f=true;
                dp[i][m-1]=0;
            }
            else dp[i][m-1]=1;
            }
            //cout<<dp[i][m-1]<<" ";
        }
        f=false;
        for(int i=m-1;i>=0;i--){
            if(f) dp[n-1][i]=0;
            else{
            if(grid[n-1][i]==1){
                f=true;
                dp[n-1][i]=0;
            }
            else dp[n-1][i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                long long r=dp[i][j+1];
                long long d=dp[i+1][j];
                dp[i][j]=r+d;
                }
            }
        }
        return dp[0][0];  
    }
};