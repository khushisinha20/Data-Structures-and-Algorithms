// leetcode.com/problems/minimum-cost-to-convert-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long INF = LLONG_MAX / 4;

    string getKey(string a, string b) {
        char DELIMETER = '-';
        return a + DELIMETER + b;
    }

    unordered_map<string, vector<pair<string, int>>> createGraph(
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        unordered_map<string, vector<pair<string, int>>> graph;
        int n = cost.size();
        for (int i = 0; i < n; ++i) {
            graph[original[i]].push_back({changed[i], cost[i]});
        }
        return graph;
    }

    unordered_map<string, long long> dijkstra(
        string start,
        unordered_map<string, vector<pair<string, int>>>& graph
    ) {
        unordered_map<string, long long> minCost;
        priority_queue<
            pair<long long, string>,
            vector<pair<long long, string>>,
            greater<>
        > minHeap;

        minHeap.push({0, start});
        minCost[start] = 0;

        while (!minHeap.empty()) {
            auto [currCost, currNode] = minHeap.top();
            minHeap.pop();

            if (currCost > minCost[currNode]) continue;

            for (auto& [neighborNode, edgeWeight] : graph[currNode]) {
                if (!minCost.count(neighborNode) ||
                    currCost + edgeWeight < minCost[neighborNode]) {
                    minCost[neighborNode] = currCost + edgeWeight;
                    minHeap.push({currCost + edgeWeight, neighborNode});
                }
            }
        }
        return minCost;
    }

    unordered_map<string, long long> getMinCostFromNode2Node(
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        unordered_map<string, vector<pair<string, int>>> graph =
            createGraph(original, changed, cost);

        unordered_map<string, long long> minCost;

        for (auto& str : original) {
            auto minCostForStrMap = dijkstra(str, graph);
            for (auto& [targetStr, minCostForStr] : minCostForStrMap) {
                minCost[getKey(str, targetStr)] = minCostForStr;
            }
        }
        return minCost;
    }

    vector<int> getLengths(vector<string>& strs) {
        unordered_set<int> st;
        for (auto& s : strs)
            st.insert(s.length());
        return vector<int>(st.begin(), st.end());
    }

    long long minimumCostHelper(
        string& source,
        string& target,
        unordered_map<string, long long>& minCost,
        unordered_map<int, unordered_set<string>>& validSource,
        vector<int>& lengths,
        int index,
        vector<long long>& dp
    ) {
        if (index == source.length())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        long long ans = INF;

        if (source[index] == target[index]) {
            ans = minimumCostHelper(
                source, target, minCost, validSource,
                lengths, index + 1, dp
            );
        }

        for (auto& length : lengths) {
            if (index + length > source.length()) continue;

            string src = source.substr(index, length);
            if (!validSource[length].count(src)) continue;

            string dest = target.substr(index, length);
            auto it = minCost.find(getKey(src, dest));
            if (it == minCost.end()) continue;

            long long nextCost = minimumCostHelper(
                source, target, minCost, validSource,
                lengths, index + length, dp
            );

            if (nextCost != INF)
                ans = min(ans, it->second + nextCost);
        }

        return dp[index] = ans;
    }

    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        unordered_map<string, long long> minCost =
            getMinCostFromNode2Node(original, changed, cost);

        vector<int> lengths = getLengths(original);

        unordered_map<int, unordered_set<string>> validSource;
        for (auto& s : original)
            validSource[s.length()].insert(s);

        vector<long long> dp(source.length(), -1);

        long long ans = minimumCostHelper(
            source, target, minCost,
            validSource, lengths, 0, dp
        );

        return ans >= INF ? -1 : ans;
    }
};

