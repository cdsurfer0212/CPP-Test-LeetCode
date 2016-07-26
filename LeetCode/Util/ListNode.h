//
//  ListNode.h
//  LeetCode
//
//  Created by Sean Zeng on 6/28/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {
        //std::cout << "val: " << val << std::endl;
        //printf("val: %d\n", val);
    }
};

#endif /* ListNode_h */
