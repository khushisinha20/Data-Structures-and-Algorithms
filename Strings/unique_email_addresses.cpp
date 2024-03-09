//leetcode.com/problems/unique-email-addresses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processEmail(string& email) {
        string processedEmail;
        bool ignorePeriod = true;
        bool ignore = false;
        bool isDomainName = false;
        
        for (char& c: email) {
            if (c == '@') {
                ignore = false;
                ignorePeriod = false;
                isDomainName = true;
                processedEmail += c;
            } else if (!isDomainName) {
                if (c == '.') {
                    if (!ignorePeriod)
                        processedEmail += c;
                } else if (c == '+') {
                    ignore = true;
                } else {
                    if (!ignore)
                        processedEmail += c;
                }
            } else
                processedEmail += c;
        }
        
        return processedEmail;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        
        for (string& email: emails) 
            uniqueEmails.insert(processEmail(email));
        
        return uniqueEmails.size();
    }
};