#include <vector>

using namespace std;

class Solution {
public:
    struct Restaurant {
        int id, rating, vegan_friendly, price, distance;

        bool operator<(const Restaurant &r) const {
            if (rating != r.rating) return rating > r.rating;
            else return id > r.id;
        }
    };

    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<Restaurant> v;
        for (auto &r : restaurants) {
            int id = r[0], rating = r[1], vegan_friendly = r[2], max_price = r[3], max_distance = r[4];
            if (!vegan_friendly && veganFriendly) continue;
            if (max_price > maxPrice) continue;
            if (max_distance > maxDistance) continue;
            v.push_back({id, rating, vegan_friendly, max_price, max_distance});
        }
        sort(v.begin(), v.end());
        vector<int> res(v.size());
        for (int i = 0; i < v.size(); i++) {
            res[i] = v[i].id;
        }
        return res;
    }
};