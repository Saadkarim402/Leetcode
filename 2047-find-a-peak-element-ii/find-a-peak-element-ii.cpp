class Solution {
    private:
    int solve(int mid,vector<vector<int>>& mat,int n){
        int ind=0,ans=-1e9;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>ans){
                ans=mat[i][mid];
                ind=i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int ind=solve(mid,mat,n);
            int left=(mid-1)>0?mat[ind][mid-1]:-1;
            int right=(mid+1)<m?mat[ind][mid+1]:-1;
            if(mat[ind][mid]>left&&mat[ind][mid]>right)return {ind,mid};
            else if(mat[ind][mid]<left) h=mid-1;
            else l=mid+1;
        }
        return {-1,-1};
        
        
    }
};