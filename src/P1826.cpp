#include <vector>

using namespace std;

class Solution {
public:
    int badSensor(vector<int> &sensor1, vector<int> &sensor2) {
        int n = sensor1.size();
        for (int i = 0; i < n - 1; i++) {
            if (sensor1[i] != sensor2[i]) {
                bool flag = true;
                if (sensor1[i + 1] == sensor2[i]) {
                    for (int j = i + 1; j < n; j++) {
                        if (sensor1[j] != sensor2[j - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return 2;
                }
                if (sensor2[i + 1] == sensor1[i]) {
                    flag = true;
                    for (int j = i + 1; j < n; j++) {
                        if (sensor2[j] != sensor1[j - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return 1;
                }
                return -1;
            }
        }
        return -1;
    }
};