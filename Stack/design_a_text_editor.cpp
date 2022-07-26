//leetcode.com/problems/design-a-text-editor/

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    string before_cursor;
    string after_cursor;
    TextEditor() {
        before_cursor = "";
        after_cursor = "";
    }
    
    void addText(string text) {
        before_cursor += text;
    }
    
    int deleteText(int k) {
        int characters_deleted = min(k, (int)before_cursor.length());
        for (int i = 0; i < characters_deleted; ++i)
            before_cursor.pop_back();
        return characters_deleted;
    }
    
    string cursorLeft(int k) {
        int characters_moved = min(k, (int)before_cursor.length());
        for (int i = 0; i < characters_moved; ++i) {
            after_cursor.push_back(before_cursor.back());
            before_cursor.pop_back();
        }
        
        int chars_before_cursor = min(10, (int)before_cursor.length());
        return before_cursor.substr(before_cursor.length() - chars_before_cursor);
    }
    
    string cursorRight(int k) {
        int characters_moved = min(k, (int)after_cursor.length());
        for (int i = 0; i < characters_moved; ++i) {
            before_cursor.push_back(after_cursor.back());
            after_cursor.pop_back();
        }
        int chars_before_cursor = min(10, (int)before_cursor.length());
        return before_cursor.substr(before_cursor.length() - chars_before_cursor);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */