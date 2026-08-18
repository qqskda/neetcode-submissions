class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // we were told that timestamp is strictly increasing

        store[key].push_back(pair<int,string>(timestamp, value));
    }
    
    string get(string key, int timestamp) {

        if (store.find(key) == store.end()) return "";
        
        string result = "";
        int left = 0;
        int right = store[key].size()-1;

        while (left <= right)
        {
            int mid = left + (right-left)/2;
            // look for timestamp
            if (store[key][mid].first == timestamp)
            {
                result = store[key][mid].second;
                break;
            }
            else if (store[key][mid].first < timestamp)
            {
                // save the upper_bound timestamp value 
                result = store[key][mid].second;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return result;
    }
};
