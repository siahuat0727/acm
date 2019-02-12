/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.06%)
 * Total Accepted:    338.3K
 * Total Submissions: 844.4K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
    void bt(const string& digits, string prefix, int index, string letters[], vector<string> &ans) {
        if (digits.length() == index) {
            if (prefix.length() > 0)
                ans.push_back(prefix);
            return;
        }
        for (char c: letters[digits[index]-'0'])
            bt(digits, prefix + string(1, c), index+1, letters, ans);
    }

    vector<string> letterCombinations(string digits) {
        string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        bt(digits, "", 0, letters, ans);
        return ans;
    }
};
