#include <unordered_map>
#include <string>
#include <map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, map<int, string>> m;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        else {
            if (timestamp < m[key].begin()->first) return "";
            auto t = m[key].upper_bound(timestamp);
            t--;
            return t->second;
        }
    }
};