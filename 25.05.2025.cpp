class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return backtrack(s, wordSet, 0, memo);
    }
    
private:
    vector<string> backtrack(const string& s, const unordered_set<string>& wordSet, int start, unordered_map<int, vector<string>>& memo) {
        // If we have reached the end of the string, return a list with an empty string
        if (start == s.size()) {
            return {""};
        }
        
        // If this subproblem is already solved, return the result from memo
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        vector<string> sentences;
        // Try every possible end position for the current prefix
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            // If the current prefix is a valid word, recursively solve for the remaining suffix
            if (wordSet.find(word) != wordSet.end()) {
                vector<string> remaining_sentences = backtrack(s, wordSet, end, memo);
                // Append the current word to each of these sentences
                for (const string& sentence : remaining_sentences) {
                    if (!sentence.empty()) {
                        sentences.push_back(word + " " + sentence);
                    } else {
                        sentences.push_back(word);
                    }
                }
            }
        }
        
        // Memoize the result
        memo[start] = sentences;
        return sentences;
    }
};
