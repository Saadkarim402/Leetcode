class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        int u=k;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=u;j>=1;j--){
                for(int k=0;k<=1;k++){
                    int idle=dp[i+1][j][k];
                    if(k){
                        int buy=dp[i+1][j][0]-a[i];
                        dp[i][j][k]=max(idle,buy);
                    }
                    else{
                        int sell=dp[i+1][j-1][1]+a[i];
                        dp[i][j][k]=max(idle,sell);
                    }
                }
            }
        }
        return dp[0][k][true];  
        
    }
};