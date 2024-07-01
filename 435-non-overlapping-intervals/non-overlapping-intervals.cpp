class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](const auto&a,const auto&b){
            return a[1]<b[1];
        });
        int i=1;
        int n=a.size();
        int en=a[0][1];
        int ans=0;
        while(i<n){
            if(en>a[i][0]){
                ans++;
            }
            else{
                en=a[i][1];
            }
            i++;
        }
        return ans; 
    }
};