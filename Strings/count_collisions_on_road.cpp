//leetcode.com/problems/count-collisions-on-a-road/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLeftCars(string& directions) {
        int left_cars = 0;
        while (left_cars < directions.length() && directions[left_cars] == 'L')
            ++left_cars;
        return left_cars;
    }
    
    int countRightCars(string& directions) {
        int right_cars = directions.length() - 1;
        while (right_cars >= 0 && directions[right_cars] == 'R') 
            --right_cars;
        return right_cars;
    }
    
    int countStationaryCars(string& directions) {
        int left = countLeftCars(directions);
        int right = countRightCars(directions);
        int stationary_cars = 0;
        for (int i = left; i <= right; ++i)
            if (directions[i] == 'S')
                ++stationary_cars;
        return stationary_cars;
    }
    
    int countCollisions(string directions) {
        return (countRightCars(directions) - countLeftCars(directions) + 1) - countStationaryCars(directions);
    }
};