

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

struct LN{
    int k;
    int v;
    LN* next;
    LN* prev;
    LN(int key, int value){
        k = key;
        v = value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private:
    LN *head;
    LN *tail;
    unordered_map<int, LN*> m;
    int cap;

    void move_head(LN * n){
        if (n->prev){n->prev->next = n->next;}
        if (n->next){n->next->prev = n->prev;}

        n->next = head->next;
        head->next->prev = n;
        head->next = n;
        n->prev = head;
    }
    void remove_tail(){
        if (tail->prev == head) return;
        LN* t= tail->prev;
        int i = t->k;
        m.erase(i);
        tail->prev = t->prev;
        t->prev->next = tail;
         delete t;
    }
public:
    LRUCache(int capacity) {
        if (capacity <= 0){return;}
        cap = capacity;
        head = new LN(-1, -1);
        tail = new LN(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()){
            return -1;
        }
        // move the node to head->next
        LN* n = it->second;
        move_head(n);
        return n->v;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){
            LN * n = it->second;
            n->v = value;
            move_head(n);
            return;
        }
        LN* n = new LN(key, value);
        if (m.size() >= cap){
            remove_tail();
        }
        move_head(n);
        m[key] = n;
    }
};





