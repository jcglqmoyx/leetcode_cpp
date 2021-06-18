#include <string>
#include <unordered_map>

using namespace std;

class Logger {
public:
    unordered_map<string, int> map;

    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (map.count(message) && timestamp - map[message] < 10) {
            return false;
        } else {
            map[message] = timestamp;
            return true;
        }
    }
};