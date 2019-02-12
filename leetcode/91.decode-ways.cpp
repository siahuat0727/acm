/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.75%)
 * Total Accepted:    232.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution {
public:
    int char2int(char c) {
        return c - '0';
    }

    bool isBetween(int n, int low, int high) {
        return low <= n && n <= high;
    }

    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int prev = 1, cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            int temp = cur;
            if (s[i] == '0') {
                if (!(isBetween(char2int(s[i-1]), 1, 2)))
                    return 0;
                cur = prev; // s[i-1] should be together with s[i]
            } else if (isBetween(char2int(s[i-1])*10 + char2int(s[i]), 10, 26)) {
                cur = cur + prev;
            }
            prev = temp;
        }
        return cur;
    }
};
