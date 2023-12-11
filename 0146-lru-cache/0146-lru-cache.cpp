class LRUCache {
public:
    class node{
      public:
        int key ;
        int value;
        node* next;
        node* prev;
        node(int key_,int val_)
        {
            key=key_;
            value =val_;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode)
    {
        node* nextToHead = head->next;
        newnode->next = nextToHead;
        newnode->prev = head;
        head->next = newnode;
        nextToHead->prev = newnode;
    }
    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node* keynode = mp[key];
            int res = keynode->value;
            deletenode(keynode);
            addnode(keynode);
            mp[key] = head->next;
            cout<<res;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value_) {
        if(mp.find(key_)!=mp.end())
        {
            node* existingnode = mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value_));
            mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */