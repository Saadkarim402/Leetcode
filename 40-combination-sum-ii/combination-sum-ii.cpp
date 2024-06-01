class Solution {
    vector<vector<int>>ans;
    void solve(int i,vector<int>&v,int n,vector<int>&temp,int k){
        if(k==0){
        ans.push_back(temp);
        return;
        }
        if(i==n)return;
        if(k<v[i])return;
        for(int ind=i;ind<n;ind++){
            if(i!=ind&&v[ind]==v[ind-1])continue;
            temp.push_back(v[ind]);
            solve(ind+1,v,n,temp,k-v[ind]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        vector<int>temp;
        ans.clear();
        sort(nums.begin(),nums.end());
        solve(0,nums,nums.size(),temp,k);
        return ans;
        
    }
};