**********QUESTION********
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

********SOLUTION***********
class Solution {
public:
    int longestPalindrome(string s){
        unordered_set<char> charSet;
        int length = 0;
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                charSet.insert(c);
            }
        }
        if (!charSet.empty()) {
            length += 1;
        }
        return length;
        
    }
};
