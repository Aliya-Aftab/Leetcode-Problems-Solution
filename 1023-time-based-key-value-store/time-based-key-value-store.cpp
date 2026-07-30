class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
       if(mp.find(key)==mp.end()){
            return "";
       } 
       auto &v=mp[key];
       string res="";
       int lo=0, hi=v.size()-1;
       while(lo <= hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid].first <= timestamp){
            res=v[mid].second;
            lo=mid+1;
        }
        else{
            hi=mid-1; 
       }
       }
       return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */