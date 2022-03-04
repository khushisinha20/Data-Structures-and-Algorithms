#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1; 
        int min_boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
                --right;
                ++min_boats;
            } else {
                ++min_boats;
                --right;
            }
        }
        return min_boats;
    }
};