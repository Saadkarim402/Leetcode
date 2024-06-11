class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto it:arr1){
            mp[it]++;
        }
        vector<int>ans;
        for(auto it:arr2){
            int k=mp[it];
            while(k--){
                ans.push_back(it);
                mp[it]--;
            }
        }
        for(auto it:mp){
            int k=it.second;
            while(k--){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};