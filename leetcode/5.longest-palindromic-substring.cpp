/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.72%)
 * Total Accepted:    411.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        char str[len + 1];
        strcpy(str, s.c_str());
        int max_len = 0;
        for (int i = 0; i < len; ++i) {
            int len = 1;
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < len) {
                if (str[l] != str[r])
                    break;


            }


        }

    }
};
