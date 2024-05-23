class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<int>hash(n,1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0&&dp[j]+1>dp[i]){
                    hash[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=-1,last=0;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                last=i;
            }
        }
        vector<int>temp;
        temp.push_back(a[last]);
        while(last!=hash[last]){
            last=hash[last];
            temp.push_back(a[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};