/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (33.69%)
 * Total Accepted:    109.6K
 * Total Submissions: 325.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空
 * 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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

#include <iostream>
#define DEBUG_

#ifdef DEBUG_
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result_list = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* cur = result_list;
        int carry = 0;
        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = x + y + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry != 0) {
            cur->next = new ListNode(carry);
        }
        return result_list->next;
    }
};
