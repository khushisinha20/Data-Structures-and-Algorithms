//leetcode.com/problems/number-of-matching-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCeil(vector<int>& indices, int target) {
        int low = 0;
        int high = indices.size() - 1;
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (indices[mid] > target) {
                result = indices[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    unordered_map<char, vector<int>> getIndices(string& s) {
        unordered_map<char, vector<int>> indexMap;
        
        for (int i = 0; i < s.length(); ++i)
            indexMap[s[i]].push_back(i);
        
        return indexMap;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        auto indexMap = getIndices(s);
        
        int matchingSubsequences = 0;
        
        for (auto& word: words) {
            bool isSubsequence = true;
            int previousIndex = -1;
            for (int i = 0; i < word.length(); ++i) {
                if (i == 0) {
                    if (indexMap.find(word[i]) == indexMap.end()) {
                        isSubsequence = false;
                        break;
                    }
                    previousIndex = indexMap[word[i]].front();
                } else {
                    if (indexMap.find(word[i]) == indexMap.end()) {
                        isSubsequence = false;
                        break;
                    }
                    
                    int justGreaterThanPrevious = getCeil(indexMap[word[i]], previousIndex);
                    if (justGreaterThanPrevious == -1) {
                        isSubsequence = false;
                        break;
                    } else
                        previousIndex = justGreaterThanPrevious;
                }
            }
            
            if (isSubsequence)
                ++matchingSubsequences;
            
        }
        
        return matchingSubsequences;
    }
};