#include <iostream>
#include <map>
#include <list>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        map[key] = cache.begin();
        return kv.second; // value
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) {
            if (cache.size() == cap) {
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
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

int main(){
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout<<cache->get(1)<<endl;       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cout<<cache->get(1)<<endl;       // 返回 -1 (未找到)
    cout<<cache->get(3)<<endl;       // 返回  3
    cout<<cache->get(4)<<endl;       // 返回  4


}
