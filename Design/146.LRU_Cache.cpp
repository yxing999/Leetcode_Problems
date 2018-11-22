/*
A famous design problem. But it is not hard after getting core data structure.
An integer capacity_, the size of the cache;
a list<pair<int,int>> cache, the content of the cache;
an unordered_map<int,list<pair<int,int>>::iterator> mp, helper for checking existence of key in O(1). 

Time: get:O(1),
      put:O(1).
*/


class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            cache.splice(cache.begin(),cache,it->second);
            return it->second->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second->second=value;
            cache.splice(cache.begin(),cache,it->second);
            return;
        }
        else{
            cache.push_front({key,value});
            mp[key]=cache.begin();
            if(cache.size()>capacity_){
                int k=cache.back().first;
                cache.pop_back();
                mp.erase(k);
            }
        }
    }
private:
    int capacity_;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
};