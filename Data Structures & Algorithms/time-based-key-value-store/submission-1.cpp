class TimeMap {
    map<string, map<int, string>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!timemap.contains(key)) return "";

        auto &timestamps = timemap[key];
        auto itr = timestamps.upper_bound(timestamp);

        if (itr == timestamps.begin()) return "";
        --itr;
        return itr->second;
    }
};
