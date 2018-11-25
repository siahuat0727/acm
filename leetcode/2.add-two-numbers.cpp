/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.56%)
 * Total Accepted:    655.8K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL;
        ListNode **temp = &ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = (int)(sum >= 10);
            int digit = carry ? sum - 10 : sum;
            *temp = new ListNode(digit);
            l1 = l1->next;
            l2 = l2->next;
            temp = &((*temp)->next);
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            carry = (int)(sum >= 10);
            int digit = carry ? sum - 10 : sum;
            *temp = new ListNode(digit);
            l1 = l1->next;
            temp = &((*temp)->next);
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            carry = (int)(sum >= 10);
            int digit = carry ? sum - 10 : sum;
            *temp = new ListNode(digit);
            l2 = l2->next;
            temp = &((*temp)->next);
        }
        if (carry) {
            *temp = new ListNode(1);
        }
        return ans;
    }
};
