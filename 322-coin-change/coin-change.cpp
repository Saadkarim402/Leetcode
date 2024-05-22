class Solution {
public:
    int coinChange(vector<int>& coins, int tar) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        for(int i=0;i<=tar;i++){
            if(i%coins[n-1]==0){
                dp[n-1][i]=i/coins[n-1];
            }
            else dp[n-1][i]=1e9;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=tar;j++){
                int take=1e9;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                int nottake=dp[i+1][j];
                dp[i][j]=min(take,nottake);
            }
        }
        if(dp[0][tar]>=1e9)return -1;
        return dp[0][tar];
    }
};