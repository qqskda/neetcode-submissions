class LRUCache {
    int _capacity;
    unordered_map<int, list<pair<int,int>>::iterator> _getter;
    list<pair<int,int>> _setter;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        // return -1 if does not exist
        // O(1) average time
        if (_getter.contains(key))
        {
            auto [k, v] = *_getter[key];
            _setter.erase(_getter[key]);
            _setter.push_front({k,v});
            _getter[key] = _setter.begin();
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // set the key-value
        // if capacity is not enough, remote the least recently used one
        // O(1) average time

        // We already have it
        if (_getter.contains(key))
        {
            _setter.erase(_getter[key]);
        }
        else if (_capacity == _setter.size())
        {
            // remove the last one
            _getter.erase(_setter.back().first);
            _setter.pop_back();
        }
        _setter.push_front({key, value});
        _getter[key] = _setter.begin();
    }
};
