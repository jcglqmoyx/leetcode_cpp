#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int ans;
    vector<bool> visited;

    int numTilePossibilities(string tiles) {
        ans = 0;
        sort(tiles.begin(), tiles.end());
        visited.resize(tiles.size(), false);
        dfs(tiles);
        return ans;
    }

    void dfs(string &tiles) {
        for (int i = 0; i < tiles.length(); i++) {
            if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                ans++;
                dfs(tiles);
                visited[i] = false;
            }
        }
    }
};