problem-->You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
Return the score of s.
**********************SOLUTION-->************************
class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
    for(int i=0;i<s.length()-1;i++){
        score +=abs(s[i]-s[i+1]);
    }
    return score;
    }
};
