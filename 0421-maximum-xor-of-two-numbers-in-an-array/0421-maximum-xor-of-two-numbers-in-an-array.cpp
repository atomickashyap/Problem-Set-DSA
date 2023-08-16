struct Node{
    Node* links[2];
    
    bool containKey(int bit)
    {
        return (links[bit] != NULL);
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node* node)
    {
        links[bit]= node;
    }
};

class Trie{
    private: Node* root = new Node();
    public : 
    
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containKey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    
    public:
    
    int getmax(int num)
    {
        Node* node = root;
        int maxiNum=0;
        for(int i = 31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containKey(!bit))
            {
                maxiNum = maxiNum | (1<<i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxiNum;
    }
    
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        
        for(auto &it: nums)
        {
            trie.insert(it);
        }
        int maxi = 0;
        for(auto &it: nums)
        {
            maxi =  max(maxi,trie.getmax(it));
        }
        return maxi;
    }
};