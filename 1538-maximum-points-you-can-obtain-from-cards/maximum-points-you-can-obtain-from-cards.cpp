class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int tot=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            tot+=a[i];
        }
        //saare cards le skte hai tb
        if(k==n)return tot;

        int l=0,r=0,sum=0;
        int ans=0;
        while(r<n){
            sum+=a[r];
            if((r-l+1)<n-k){
                r++;
            }
            else{
                ans=max(ans,tot-sum);
                sum-=a[l];
                l++;
                r++;
            }
        }
        return ans;



        
    }
};