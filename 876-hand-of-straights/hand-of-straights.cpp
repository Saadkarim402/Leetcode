class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        while (!hand.empty()) {
            int mst = 0,start = hand[0];
            while (mst < groupSize) {
                bool flag = binary_search(hand.begin(),hand.end(),start);
                if(!flag)return false;
                auto it = lower_bound(hand.begin(), hand.end(), start);
                    hand.erase(it);
                    mst++;
                    start++;
            }
        }
        return true;
    }
};