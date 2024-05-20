class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return a[0];
        }
        if(n==2){
            int k=max(a[0],a[1]);
            return k;
        }
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=a[n-1];
        dp[n-2]=0;
        for(int i=n-2;i>=1;i--){
            int rob=a[i]+dp[i+2];
            int nrob=dp[i+1];
            dp[i]=max(rob,nrob);
        }
        int ans=dp[1];
        memset(dp,0,sizeof dp);
        dp[n-1]=0;
        dp[n-2]=a[n-2];
        for(int i=n-2;i>=0;i--){
            int rob=a[i]+dp[i+2];
            int nrob=dp[i+1];
            dp[i]=max(rob,nrob);
        }
        ans=max(ans,dp[0]);
        return ans;
        
    }
};