/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.35%)
 * Total Accepted:    647.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool table[0x100] = {0};
        auto left = s.begin();
        int length = 1;
        int max_len = 0;
        for (auto right = left; right != s.end(); ++right, ++length) {
            const int idx = *right;
            if (table[idx] == false) {
                table[idx] = true;
                max_len = max(max_len, length);
            } else {
                while (*left != idx) {
                    table[*left] = false;
                    left++;
                    length--;
                }
                left++;
                length--;
            }
        }
        return max_len;
    }
};
