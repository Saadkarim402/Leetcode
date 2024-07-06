class Solution {
public:
    int passThePillow(int n, int k) {
        int j=(k)/(n-1);
        int h=(k)%(n-1);
        if(j&1){
            return (n-1)-h+1;
        }
        else{
            return h+1;
        }
        
    }
};