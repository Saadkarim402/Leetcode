class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dp[i][m-1]=a[i][m-1];
        }
        for(int i=0;i<m;i++){
            dp[n-1][i]=a[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(a[i][j]==0)dp[i][j]=0;
                else{
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
                }
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
                s+=dp[i][j];
            }
            cout<<endl;
        }
        return s; 
    }
};