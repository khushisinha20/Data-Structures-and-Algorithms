//leetcode.com/problems/watering-plants-ii/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int number_of_times = 0;
        int originalCapacityA = capacityA;
        int originalCapacityB = capacityB;
        int left = 0;
        int right = plants.size() - 1;
        while (left <= right) {
            if (left == right) {
                if (capacityA >= capacityB) {
                    if (plants[left] > capacityA) {
                        ++number_of_times;   
                        capacityA = originalCapacityA;
                        capacityA -= plants[left];
                        ++left;
                    } else {
                        capacityA -= plants[left];
                        ++left;
                    }
                } else {
                    if (plants[right] > capacityB) {
                        ++number_of_times;
                        capacityB = originalCapacityB;
                        capacityB -= plants[right];
                        --right;
                    } else {
                        capacityB -= plants[right];
                        --right;
                    }
                }
            } else {
                if (plants[left] > capacityA) {
                    ++number_of_times;   
                    capacityA = originalCapacityA;
                    capacityA -= plants[left];
                    ++left;
                } else {
                    capacityA -= plants[left];
                    ++left;
                }
                if (plants[right] > capacityB) {
                    ++number_of_times;
                    capacityB = originalCapacityB;
                    capacityB -= plants[right];
                    --right;
                } else {
                    capacityB -= plants[right];
                    --right;
                }
            }
        }
        return number_of_times;
    }
};