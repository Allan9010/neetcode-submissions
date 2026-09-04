class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = timemap.find(key);
        if(it == timemap.end()) return "";
        
        const vector<pair<string, int>>& arr = it->second;
        int tail = arr.size() - 1;
        int head = 0;
        while(head < tail){
            int mid = head + (tail - head + 1) / 2;
            if(timestamp < arr[mid].second) tail = mid - 1;
            else head = mid;
        }
        return timestamp >= arr[head].second ? arr[head].first : "";
    }

private:
    unordered_map<string, vector<pair<string, int>>> timemap;    
};
