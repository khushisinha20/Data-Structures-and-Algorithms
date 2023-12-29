// leetcode.com/problems/encrypt-and-decrypt-strings/

#include <bits/stdc++.h>
using namespace std;

class Encrypter {
public:
    unordered_map<char, string> encryptionMap;
    unordered_map<string, int> decryptionMap;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i)
            encryptionMap[keys[i]] = values[i];
        
        for (int i = 0; i < dictionary.size(); ++i)
            ++decryptionMap[encrypt(dictionary[i])];
    }
    
    string encrypt(string word1) {
        string result;
        for (int i = 0; i < word1.length(); ++i) {
            if (encryptionMap.find(word1[i]) == encryptionMap.end())
                return "";
            result += encryptionMap[word1[i]];
        }
        
        return result;
    }
    
    int decrypt(string word2) {
        if (!decryptionMap.count(word2))
            return 0;
        return decryptionMap[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */