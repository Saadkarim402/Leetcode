class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            int rob=a[i]+dp[i+2];
            int nrob=dp[i+1];
            dp[i]=max(rob,nrob);
        }
        return dp[0];
        
    }
};