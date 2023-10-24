class Node{
    public:
    int key , val, cnt;
    Node* prev;
    Node* next;

    Node(int keyi , int value){
        key = keyi;
        val = value;
        cnt = 1;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;
    int size;

    DLL(){
        head = new Node(0 , 0);
        tail = new Node(0 , 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void add(Node* node){
        Node* temp = head->next;
        temp->prev = node;
        node->next = temp;
        head->next = node;
        node->prev = head;
        size++;
    }

    void remove(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delNext->prev = delPrev;
        delPrev->next = delNext;
        size--;
    }
};

class LFUCache {
public:
    int cap , size , min;
    unordered_map<int , Node*> keyNode;
    unordered_map<int , DLL*> freqListMap;

    LFUCache(int capacity) {
        cap = capacity;    
        size = 0;
        min = 1;
    }

    void update(Node* node){
        keyNode.erase(node->key);
        DLL* oldList = freqListMap[node->cnt];
        oldList->remove(node);

        if(node->cnt == min && oldList->size == 0) min++;
        DLL* newList = new DLL();
        if(freqListMap.find(node->cnt  +  1) != freqListMap.end()){
            newList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        newList->add(node);
        freqListMap[node->cnt] = newList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val= node->val;
            update(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            update(node);
        }else{
            if(size == cap){
                DLL* list = freqListMap[min];
                keyNode.erase(list->tail->prev->key);
                list->remove(list->tail->prev);
                size--;
            }
            size++;

            min = 1;
            DLL* temp = new DLL();
            if(freqListMap.find(min) != freqListMap.end()){
                temp = freqListMap[min];
            }

            Node* node = new Node(key , value);
            temp->add(node);
            keyNode[key] = node;
            freqListMap[min] = temp;
        }
    }
};
