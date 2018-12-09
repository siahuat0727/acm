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
    int palindrome(int l, int r, int len, char* str) {
        int length = 0;
        while (l >= 0 && r < len) {
            if (str[l] != str[r])
                break;
            length += 2;
            --l;
            ++r;
        }
        return length;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        char str[len + 1];
        strcpy(str, s.c_str());
        string ret;
        int max_len = 0;
        for (int i = 0; i < len; ++i) {
            int l = i - 1, r = i + 1;
            int length = palindrome(l, r, len, str) + 1;
            if (max_len < length) {
                max_len = length;
                ret = s.substr(i-length/2, length);
            }

            l = i;
            r = i+1;
            length = palindrome(l, r, len, str);
            if (max_len < length) {
                max_len = length;
                ret = s.substr(i-length/2+1, length);
            }
        }
        return ret;
    }
};
