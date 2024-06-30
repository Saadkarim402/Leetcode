class Solution {
    struct Node{
        //for bit 0 and 1
        Node*arr[2];

        //functions
        //getkey
        bool getkey(int x){
            return (arr[x]!=NULL);
        }
        void put(int x,Node*node){
            arr[x]=node;
        }
        Node*next(int x){
            return arr[x];
        }
    };
    class Trie{
        private:Node*root;
        public:
        //constructor
        Trie(){
            root=new Node();
        }
        //functions of trie 

        //insertion
        void insert(int k){
            Node*node=root;
            for(int i=31;i>=0;i--){
                //get the ith bit
                int bit=((k>>i)&1);
                if(!node->getkey(bit)){
                    node->put(bit,new Node());
                }
                node=node->next(bit);
            }
        }

        //checking part
        int check(int x){
            Node*node=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                //get the ith bit
                int bit=!((x>>i)&1);
                if(node->getkey(bit)){
                    ans+=(1<<i);
                    node=node->next(bit);
                }
                else{
                node=node->next(!bit);
                }
            }
            return ans;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        int ans=0;
        //insertion part
        for(int i=0;i<n;i++){
            trie.insert(nums[i]);
        }
        //checking part
        for(int i=0;i<n;i++){
            int k=trie.check(nums[i]);
            ans=max(ans,k);
        }
        return ans;
    }
};