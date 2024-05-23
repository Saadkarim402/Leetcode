class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
                for(int k=0;k<=1;k++){
                    int idle=dp[i+1][k];
                    if(k){
                        int buy=dp[i+1][0]-a[i];
                        dp[i][k]=max(idle,buy);
                    }
                    else{
                        int sell=dp[i+1][1]+a[i];
                        dp[i][k]=max(idle,sell);
                    }
            }
        }
        return dp[0][true];  
        
    }
};