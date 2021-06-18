//class Solution {
//public:
//    int sumNums(int n) {
//        n && n == sumNums(n - 1);
//        return n;
//    }
//};

class Solution {
public:
    int sumNums(int n) {
        int sum = 0;
        int a = n, b = n + 1;

        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;
        (b & 1) && (sum += a);
        a <<= 1;
        b >>= 1;

        return sum >> 1;
    }
};