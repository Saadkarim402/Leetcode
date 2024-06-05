class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,l=0,r=0,maxi=0;
        int n=s.size();
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);
            if((r-l+1)-maxi>k){
                mp[s[l]]--;
                l++;
            }
            else{
                ans=max(ans,(r-l+1));
            }
            r++;
        }
        return ans;
    }
};