class Solution {

public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        int m=1e9+7;
        stack<pair<int,int>>pre,suf;
        int pre1[n],suf1[n];
        //suffix
        for(int i=n-1;i>=0;i--){
            while(!suf.empty()&&suf.top().first>=a[i]){
                suf.pop();
            }
            if(!suf.empty()) suf1[i]=suf.top().second;
            else suf1[i]=n;
            suf.push({a[i],i});
        }
        //pre
        for(int i=0;i<n;i++){
            while(!pre.empty()&&pre.top().first>a[i]){
                pre.pop();
            }
            if(!pre.empty()) pre1[i]=pre.top().second;
            else pre1[i]=-1;
            pre.push({a[i],i});
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long l=(suf1[i]-i),r=(i-pre1[i]);
            long long t=((l%m)*(r%m))%m;
            long long t1=(t*a[i])%m;
            ans+=t1%m;
        }
        return ans%m;   
    }
};