/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 *
 * https://leetcode.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (24.17%)
 * Total Accepted:    1.7K
 * Total Submissions: 6.3K
 * Testcase Example:  '[3,1,3,6]'
 *
 * Given an array of integers A with even length, return true if and only if it
 * is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0
 * <= i < len(A) / 2.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [3,1,3,6]
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [2,1,2,6]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [4,-2,2,-4]
 * Output: true
 * Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4]
 * or [2,4,-2,-4].
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [1,2,4,16,8,4]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 30000
 * A.length is even
 * -100000 <= A[i] <= 100000
 *
 *
 *
 *
 *
 *
 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> m;
        for (int a: A)
            m[a]++;

        vector<int> v;
        for (auto it: m)
            v.push_back(it.first);
        sort(v.begin(), v.end(), [](int a, int b){return abs(a) < abs(b);});

        for (int k: v) {
            if (m[k] > m[2*k])
                return false;
            m[2*k] -= m[k];
        }
        return true;
    }
};
