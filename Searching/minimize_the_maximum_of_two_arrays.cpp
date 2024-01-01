//leetcode.com/problems/minimize-the-maximum-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getLCM(long long a, long long b) {
        return (a * b) / __gcd(a, b);
    }
    
    bool meetsCriteria(int num, int& divisor1, int& divisor2, int& uniqueCnt1, int& uniqueCnt2) {
        long long elementsInArray1 = num - num / divisor1;
        long long elementsInArray2 = num - num / divisor2;
        long long elementsInEitherArray = num - num / getLCM(divisor1, divisor2);
        
        return elementsInArray1 >= uniqueCnt1 and
               elementsInArray2 >= uniqueCnt2 and
               elementsInEitherArray >= (uniqueCnt1 + uniqueCnt2);
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int left = 0;
        int right = INT_MAX;
        int ans = -1;
        
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (meetsCriteria(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                ans = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        
        return ans;
    }
};