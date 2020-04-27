//LRU Cache
// 用的思想是最近计组学习的方面的思想

// LRU - Least Recently Used Cache

// 没有想到实现这么思维~~~
// Access to a random key in O(1) -> hashtable
// Remove the last entry in LRU cache in O(1) -> list / vector
// Add/move an entry to the front of LRU cache in O(1) ->list

// 单独一种容器没办法实现这个操作，一定要conbine 多个容器
// 这是dl 又concise 数据结构完全达到O(1)标准的答案

// awsl 好难啊~~， 明天希望能实现一下~~
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};
