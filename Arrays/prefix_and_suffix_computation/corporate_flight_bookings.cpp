/*leetcode.com/problems/corporate-flight-bookings*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> total_seats(n + 2, 0);
        for (int i = 0; i < bookings.size(); ++i) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];
            total_seats[first] += seats;
            total_seats[last + 1] -= seats;
        }
        vector<int> answer;
        int curr_sum = 0;
        for (int i = 1; i <= n; ++i) {
            curr_sum += total_seats[i];
            answer.push_back(curr_sum);
        }
        return answer;
    }
};