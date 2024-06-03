class Solution {
public:
    int minBitFlips(int st, int en) {
        int c=0;
        for(int i=0;i<32;i++){
            int k1=(st>>i)&1;
            int k2=(en>>i)&1;
            if(k1!=k2)c++;
        }
        return c;  
    }
};