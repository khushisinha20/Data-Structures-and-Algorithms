#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n) {
  vector<string> res;
  if (n <= 0) {
      if (n < 0)
        return res;
      if (n == 0) {
          res.push_back("");
          return res;
       }
   }
   
   vector<string> paths1 = get_stair_paths(n - 1);
   vector<string> paths2 = get_stair_paths(n - 2);
   vector<string> paths3 = get_stair_paths(n - 3);
   
   for (auto path: paths1) {
       res.push_back("1" + path);
   }
   
   for (auto path: paths2) {
       res.push_back("2" + path);
   }
   
   for (auto path: paths3) {
       res.push_back("3" + path);
   }
   return res;
}