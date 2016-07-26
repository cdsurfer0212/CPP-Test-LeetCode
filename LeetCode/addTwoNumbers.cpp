//
//  addTwoNumbers.cpp
//  LeetCode
//
//  Created by Sean Zeng on 6/27/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

/**
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * https://leetcode.com/problems/add-two-numbers/
 */

#include <iostream>
#include "Util/LinkedList.h"

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
        int x = 0, y = 0, carry = 0, sum = 0;
        ListNode *h = NULL, **t = &h;
        
        while (l1 != NULL || l2 != NULL) {
            x = getValueAndMoveToNext(l1);
            y = getValueAndMoveToNext(l2);
            
            sum = carry + x + y;
            
            ListNode *ls = new ListNode(sum % 10);
            *t = ls;
            t = (&ls->next);
            
            carry = sum / 10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry % 10);
            *t = node;
        }
        
        return h;
    }
    
private:
    int getValueAndMoveToNext(ListNode* &l) {
        int x = 0;
        if (l != NULL) {
            x = l->val;
            l = l->next;
        }
        return x;
    }
};

int main(int argc, const char * argv[]) {
    LinkedList *list1 = new LinkedList();
    list1->add(2);
    list1->add(4);
    list1->add(3);
    
    LinkedList *list2 = new LinkedList();
    list2->add(5);
    list2->add(6);
    list2->add(4);
    
    Solution solution;
    ListNode *sum = solution.addTwoNumbers(list1->elementAt(0), list2->elementAt(0));
    
    ListNode *curr = sum;
    while (curr != NULL) {
        cout << curr->val << endl;
        curr = curr->next;
    }
    
    return 0;
}
