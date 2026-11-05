class TimeMap {
public:

    map<string, multiset<pair<int, string>>>mp;
    TimeMap() {
        
        mp.clear();

    }
    
    void set(string key, string value, int timestamp) {

        mp[key].insert({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        
        if(!mp.count(key))
            return "";
        auto it = mp[key].lower_bound({timestamp, ""});
        // if(it == mp[key].end())
        //     return "";
        if(it!= mp[key].end() && it->first == timestamp)
            return it->second; 

        // auto It = mp[key].upper_bound({timestamp-1, ""});
        if(it == mp[key].begin())
            return "";
        auto It = prev(it);
        if(It == mp[key].end())
            return "";
        if(It->first > timestamp)
            return "";
        return It->second;
    }
};
