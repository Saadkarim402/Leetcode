class Solution {
public:
    int minDifference(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        if(n<=4){
            return 0;
        }
        int l=0,r=n-4;
        int ans=a[r]-a[l];
        while(r<n){
            ans=min(ans,a[r]-a[l]);
            l++,r++;
        }
        return ans;
        
    }
};