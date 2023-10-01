//question link -- https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

//Solution 👇👇

class Solution {
public:
    string reverseWords(string s) {
        size_t front = 0;
        for(int i = 0; i <= s.length(); ++i){
            if(i == s.length() || s[i] == ' '){
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }

        return s;


    }
};
