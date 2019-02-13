/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (22.28%)
 * Total Accepted:    159.8K
 * Total Submissions: 717.2K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 *
 *
 */
class Solution {
public:
    string eliminateAdjacentAsterisk(string p) {
        for (int i = 1; i < p.length(); ++i)
            if (p[i] == '*' && p[i] == p[i-1])
                return eliminateAdjacentAsterisk(p.substr(0, i-1) + p.substr(i));
        return p;
    }

    bool doIsMatch(char s[], char p[]) {
        if (p[0] == '\0' && s[0] == '\0')
            return true;
        if (p[0] == '\0')
            return false;
        if (s[0] == '\0') {
            if (p[0] != '*')
                return false;
            return doIsMatch(s, p+1);
        }
        if (p[0] == '?')
            return doIsMatch(s+1, p+1);
        if (p[0] != '*') {
            if (p[0] != s[0])
                return false;
            return doIsMatch(s+1, p+1);
        }
        if (doIsMatch(s, p+1))
            return true;
        for (int i = 1; s[i-1] != '\0'; ++i)
            if (doIsMatch(s+i, p+1))
                return true;
        return false;
    }

    bool isMatch(string s, string p) {
        p = eliminateAdjacentAsterisk(p);
        char ss[s.length() + 1];
        char pp[p.length() + 1];
        strcpy(ss, s.c_str());
        strcpy(pp, p.c_str());
        return doIsMatch(ss, pp);
    }
};
