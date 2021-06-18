//class Solution {
//public:
//    int countVowelStrings(int n) {
//        int arr[] = {1, 1, 1, 1, 1};
//        for (int i = 1; i < n; i++) {
//            for (int j = 1; j < 5; j++) {
//                arr[j] += arr[j - 1];
//            }
//        }
//        int count = 0;
//        for (int num : arr) count += num;
//        return count;
//    }
//};

class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};