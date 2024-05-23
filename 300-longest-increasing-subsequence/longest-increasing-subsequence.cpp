class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //the reason why we are doing prev +1 is bcoz prev ==-1 cant be rep ,so we shift the ind by 1
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){
                int no=dp[i+1][j+1];
                int yes=0;
                if(j==-1||a[i]>a[j]){
                    yes=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(no,yes);
            }
        }
        return dp[0][0];
        
    }
};