# AlgoFlora

### LRU 146
```C++
class LRUCache {
    int max;
    list<pair<int, int>> cache; // key value
    unordered_map<int, list<pair<int, int>>::iterator> map; //key iter for search
public:
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end())
        {
            auto iter = map[key];
            auto value = iter->second;
            cache.erase(iter);
            cache.push_front({key, value});
            map[key] = cache.begin();
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end())
        {
            auto iter = map[key];
            cache.erase(iter);
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
        else
        {
            if (map.size() == max)
            {
                auto pairEnd = cache.back();
                auto keyEnd = pairEnd.first;
                map.erase(keyEnd);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```