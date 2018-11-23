/*
More difficult problem after LRU Cache.
The core data structure:
1.A user_defined class: node. with elements key,val, freq and a iterator,
  this serve as a single cache node.
2.An integer: capacity_. the capacity of the LFU system.
3.unordered_map<int,node>: cache. This is core of the LFU system. <key->node>
4.map<int,list<int>>: freq_key_. the key of this map is frequency, value is a list of key, 
  whose node frequency equals to it.
  map will sort by key automatically, so the first key is minimum frequency.

For every get and put operation, we need touch the node first, I write a single function for this.
touch process:
1.get the previous freq, and new freq.
2.remove key from the list of previous freq, if the list is empty after removing, remove the list.
3.add key to the front of new freq's list.
4.make the it of node point to where it is in the new list.

General strategy of cache design:
1.Build core structure to hold the data, usually it is a map, like unordered_map<int,node> in this problem.
2.Find some other structure to help do operations.

Time: get:O(1), put:O(1);
*/

class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        auto it=cache_.find(key);
        if(it==cache_.end()) return -1;
        else{
            touch(it->second);
            return it->second.val;
        }
    }
    
    void put(int key, int value) {
        if(capacity_==0) return;
        
        auto it=cache_.find(key);
        if(it!=cache_.end()){
            it->second.val=value;
            touch(it->second);
            return;
        }
        else{
            if(cache_.size()==capacity_){
                auto min_f=freq_key_.begin();
                int key_to_evict=min_f->second.back();
                int min_freq=min_f->first;
                cache_.erase(key_to_evict);
                freq_key_[min_freq].pop_back();
            }
            freq_key_[1].push_front(key);
            cache_[key]={key,value,1,freq_key_[1].begin()};
        }
    }
private:
    class node{
    public:
        int key;
        int val;
        int freq;
        list<int>::iterator it;
    };
    int capacity_;
    unordered_map<int,node> cache_;//<key,node>
    map<int,list<int>> freq_key_;//<freq,list<key>>
    
    void touch(node &node_){
        int pre_freq=node_.freq;
        int cur_freq=++node_.freq;
        
        freq_key_[pre_freq].erase(node_.it);
        if(freq_key_[pre_freq].empty())
            freq_key_.erase(pre_freq);
        
        freq_key_[cur_freq].push_front(node_.key);
        node_.it=freq_key_[cur_freq].begin();
    }
};