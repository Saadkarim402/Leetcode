class Solution {
public:
    int numWaterBottles(int x, int y) {
        int ans=x,c=0;
        while(x>=y){
            int k=x/y;
            int rem=x%y;
            ans+=k;
            x=k+rem;
        }
        return ans;
        
    }
};