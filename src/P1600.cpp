#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string king;

    ThroneInheritance(string kingName) : king{move(kingName)} {
    }

    void birth(string parentName, string childName) {
        edges[move(parentName)].push_back(move(childName));
    }

    void death(string name) {
        dead.insert(move(name));
    }

    void preorder(string name, vector<string> &res) {
        if (!dead.count(name)) res.push_back(name);
        for (const string &child : edges[name]) {
            preorder(child, res);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        preorder(king, res);
        return res;
    }
};