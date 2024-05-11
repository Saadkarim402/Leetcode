class Solution {
public:
    int trap(vector<int>& a) {
        int ans=0;
        int n=a.size();
        int l=0,r=n-1,lmax=0,rmax=0;
        while(l<=r){
            if(a[l]<=a[r]){
                if(lmax<=a[l]) lmax=a[l];
                else ans+=lmax-a[l]; 
                l++;
            }
            else{
                if(rmax<=a[r])rmax=a[r];
                else ans+=rmax-a[r];
                r--;
            }
        }
        return ans;

        
    }
};