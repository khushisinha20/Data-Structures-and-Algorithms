//leetcode.com/problems/reward-top-k-students/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<string> getWordsInReport(string& report) {
        istringstream iss(report);
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        return words;
    }

    int getScore(string& report, unordered_set<string>& positiveWords, unordered_set<string>& negativeWords) {
        vector<string> words = getWordsInReport(report);
        int score = 0;

        for (auto& word: words) {
            if (positiveWords.find(word) != positiveWords.end())
                score += 3;
            if (negativeWords.find(word) != negativeWords.end())
                score -= 1;
        }

        return score;
    }

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positiveWords(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negativeWords(negative_feedback.begin(), negative_feedback.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

        for (int i = 0; i < report.size(); ++i) {
            int score = getScore(report[i], positiveWords, negativeWords);
            heap.push({score, student_id[i]});
            if (heap.size() > k)
                heap.pop();
        }

        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
