#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        for (int num : arr) {
            map[num]++;
        }
        for (const auto e : map) {
            set.insert(e.second);
        }
        return set.size() == map.size();
    }
};