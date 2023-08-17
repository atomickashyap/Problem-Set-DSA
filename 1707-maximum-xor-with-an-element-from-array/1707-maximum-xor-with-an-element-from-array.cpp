struct Node{
    Node* list[2]; //storing bit
    
    bool containKey(int bit)
    {
        return (list[bit] != NULL);
    }
    Node* get(int bit)
    {
        return list[bit];
    }
    void put (int bit , Node* node)
    {
        list[bit] = node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    
public:
    void insert(int num)
    {
        Node* node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containKey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getmax(int num)
    {
        Node* node = root;
        int maxnum = 0;
        for(int i =31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containKey(!bit))
            {
                maxnum = maxnum | (1<<i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        
        vector<pair<int,pair<int,int>>> oq;
        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        vector<int> ans(q,0);
        int n = nums.size();
        int i = 0;
        Trie trie;
        int ind = 0;
	for(int i = 0;i<q;i++)
	{
		int ai = oq[i].first;
		int xi = oq[i].second.first;
		int qind = oq[i].second.second;

		
		while(ind<nums.size() && nums[ind]<=ai)
		{
			trie.insert(nums[ind]);
			ind++;	
		}
		if(ind == 0)	ans[qind] = -1;
		else{
			ans[qind] = trie.getmax(xi);
		}
	}
        return ans;
    }
};








