//#include <vector>
//#include <cmath>
//
//using namespace std;

//class Solution {
//public:
//    int countPrimes(int n) {
//        if (n <= 2) return 0;
//        int count = 0;
//        vector<int> arr(n + 1);
//        for (int i = 2; i < n; i++)
//            if (!arr[i] && is_prime(i)) {
//                count++;
//                if ((long) i * i <= n) for (int j = i * i; j <= n; j += i) arr[j] = 1;
//            }
//        return count;
//    }
//
//    bool is_prime(int n) {
//        for (int i = 2; i <= (int) sqrt(n); i++) if (n % i == 0) return false;
//        return true;
//    }
//};


#include <vector>

using namespace std;

//class Solution {
//public:
//    int countPrimes(int n) {
//        vector<int> isPrime(n, 1);
//        int ans = 0;
//        for (int i = 2; i < n; ++i) {
//            if (isPrime[i]) {
//                ans += 1;
//                if ((long long) i * i < n) {
//                    for (int j = i * i; j < n; j += i) {
//                        isPrime[j] = 0;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//};


class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
};