#include <vector>

using namespace std;

//class Solution {
//public:
//    int maxAliveYear(vector<int> &birth, vector<int> &death) {
//        int map[101] = {0};
//        for (int i = 0; i < birth.size(); i++) {
//            for (int year = birth[i]; year <= death[i]; year++) {
//                map[year - 1900]++;
//            }
//        }
//        int maximum = 0;
//        for (int n : map) maximum = max(maximum, n);
//        for (int i = 0; i < 101; i++) {
//            if (map[i] == maximum) return i + 1900;
//        }
//        return 1900;
//    }
//};

class Solution {
public:
    int maxAliveYear(vector<int> &birth, vector<int> &death) {
        int map[102] = {0};
        for (int i = 0; i < birth.size(); i++) {
            map[birth[i] - 1900]++;
            map[death[i] - 1900 + 1]--;
        }
        int maximum = 0;
        int index = 0;
        int sum = 0;
        for (int i = 0; i < 101; i++) {
            sum += map[i];
            if (sum > maximum) {
                maximum = sum;
                index = i;
            }
        }
        return index + 1900;
    }
};