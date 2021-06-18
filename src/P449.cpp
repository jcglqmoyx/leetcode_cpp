#include <string>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Codec {
public:
    string serialize(TreeNode *root) {
        string str;
        postorder(root, str);
        return str;
    }

    TreeNode *deserialize(string data) {
        vector<string> values;
        for (int i = 0; i < data.length(); i += 3) {
            values.push_back(data.substr(i, 3));
        }
        return construct(values, -1e9, 1e9);
    }

private:
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    void postorder(TreeNode *root, string &str) {
        if (!root) return;
        postorder(root->left, str);
        postorder(root->right, str);
        str += num2str(root->val);
    }

    TreeNode *construct(vector<string> &nums, int min_val, int max_val) {
        if (nums.empty()) return nullptr;
        int cur = str2num(nums.back());
        if (cur < min_val || cur > max_val) return nullptr;
        nums.pop_back();
        auto *root = new TreeNode(cur);
        root->right = construct(nums, cur, max_val);
        root->left = construct(nums, min_val, cur);
        return root;
    }

    string num2str(int num) {
        string str;
        while (num) {
            str.push_back(digits[num % 62]);
            num /= 62;
        }
        reverse(str.begin(), str.end());
        while (str.length() < 3) {
            str.insert(str.begin(), '0');
        }
        return str;
    }

    int str2num(string &str) {
        int val = 0;
        int base = 1;
        for (int i = 2; i >= 0; i--) {
            char c = str[i];
            if (isdigit(c)) val += (c - '0') * base;
            else if (isupper(c)) val += (c - 'A' + 10) * base;
            else val += (c - 'a' + 36) * base;
            base *= 62;
        }
        return val;
    }
};