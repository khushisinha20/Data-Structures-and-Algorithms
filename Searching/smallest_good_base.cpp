//leetcode.com/problems/smallest-good-base/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (long long d = 62; d >= 2; --d) {
            long long left = 2, right = pow(num, 1.0 / d);

            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long sum = 1;
                long long currentPower = 1;

                for (long long i = 1; i <= d; ++i) {
                    if (currentPower > num / mid) {
                        sum = num + 1;
                        break;
                    }
                    currentPower *= mid;
                    sum += currentPower;
                }

                if (sum == num)
                    return to_string(mid);
                else if (sum < num)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return to_string(num - 1);
    }
};
