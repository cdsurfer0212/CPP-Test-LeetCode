//
//  LinkedList.h
//  LeetCode
//
//  Created by Sean Zeng on 7/1/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include "ListNode.h"

using namespace std;

class LinkedList
{
public:
    ListNode *head;
    ListNode *tail;
    
    LinkedList();
    ~LinkedList();
    void add(int val);
    void clear();
    ListNode* elementAt(int index);
    bool insert(int index, int val);
    void print();
    bool remove(int val);
};

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::add(int val)
{
    ListNode *node = new ListNode(val);
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = tail->next;
    }
}

void LinkedList::clear()
{
    ListNode *curr = head;
    while (curr != NULL) {
        ListNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    
    head = NULL;
    tail = NULL;
}

ListNode* LinkedList::elementAt(int index)
{
    int i = 0;
    ListNode *curr = head;
    while (i < index  && curr != NULL) {
        curr = curr->next;
        i++;
    }

    if (i != index) {
        curr = NULL;
    }

    return curr;
}

bool LinkedList::insert(int index, int val) {
    ListNode *node = new ListNode(val);
    
    if (index == 0) {
        ListNode *tmp = head;
        head = node;
        node->next = tmp;
        
        if (tail == NULL) {
            tail = node;
        }
        
        return true;
        
    } else {
        ListNode* prev = elementAt(index - 1);
        
        if (prev != NULL) {
            ListNode *tmp = prev->next;
            prev->next = node;
            node->next = tmp;
            
            if (prev == tail) {
                tail = node;
            }
            
            return true;
        }
        
        return false;
    }
}

void LinkedList::print()
{
    ListNode *curr = head;
    while (curr != NULL) {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

bool LinkedList::remove(int val)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    
    while (curr != NULL) {
        if (curr->val != val) {
            prev = curr;
            curr = curr->next;
            continue;
        }
        
        if (prev == NULL) {
            head = curr->next;
            
            if (curr == tail) {
                tail = NULL;
            }
            
            delete curr;
            
        } else {
            prev->next = curr->next;
            
            if (curr == tail) {
                tail = prev;
            }
            
            delete curr;
        }
        
        return true;
    }
    
    return false;
}

#endif /* LinkedList_h */
