class LRUCache {
public:    
    LRUCache(int cap) : 
        capacity(cap),
        dummyHead(0, 0),
        dummyTail(0, 0)
    {
        hash.reserve(cap);
        head = &dummyHead;
        tail = &dummyTail;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        int ans = -1;
        if(hash.count(key)) ans = hash[key]->value;
        else return ans;

        Node* target = hash[key];
        remove(target);
        insert(target);
        return ans;
    }
    //若存在，更新(remove當前key然後insert到tail)
    //不存在，就回傳

    void put(int key, int value) {
        if(hash.count(key)){
            hash[key]->value = value;
            remove(hash[key]);
            insert(hash[key]);
        }
        else if(hash.size() < capacity){
            hash[key] = new Node(key, value);
            insert(hash[key]);
        }
        else{
            Node* target = head->next;
            hash.erase(target->key);
            remove(target);
            
            target->key = key;
            target->value = value;
            hash[key] = target;
            insert(target);
        }
    }
    //更新(remove當前key然後insert到tail)
    //新放入還沒滿(insert到tail)
    //新放入滿了(remove head，並且更新head node資訊，insert到tail)
private:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* pre;
        Node(int k, int v) : key(k), value(v), next(nullptr), pre(nullptr){}
    };

    void remove(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void insert(Node* node){
        node->next = tail;
        node->pre = tail->pre;
        tail->pre->next = node;
        tail->pre = node;
    }

    int capacity;
    Node dummyHead;
    Node dummyTail;
    unordered_map<int, Node*> hash;

    Node* head;
    Node* tail;
};
