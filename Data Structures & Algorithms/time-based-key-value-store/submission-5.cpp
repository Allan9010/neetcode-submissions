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
        
        int tail = it->second.size() - 1;
        int head = 0;
        while(head < tail){
            int mid = head + (tail - head + 1) / 2;
            if(timestamp < it->second[mid].second) tail = mid - 1;
            else head = mid;
        }
        return timestamp >= timemap[key][head].second ? timemap[key][head].first : "";
    }

private:
    unordered_map<string, vector<pair<string, int>>> timemap;    
};
