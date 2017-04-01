//
//  pow.cpp
//  LeetCode
//
//  Created by Sean Zeng on 8/2/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

/**
 * Implement pow(x, n).
 *
 * https://leetcode.com/problems/powx-n/
 */

#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = x;
        unsigned int exp = n < 0 ? -n : n;
        
        int count = 0;
        for (int i = 0; i < exp - 1; i++) {
            result *= x;
            count++;
        }
        
        if (n < 0) {
            result = 1.0 / result;
        }
        
        //cout << count << endl;
        
        return result;
    }
    
    double myPow1(double x, int n) {
        double result = 1.0;
        bool sign = n < 0;
        unsigned int exp = n < 0 ? -n : n;

        int count = 0;
        int count1 = 0;
        while (exp) {
            if (exp & 1) {
                result *= x;
                count1++;
            }
            
            exp >>= 1;
            x *= x;
            
            count++;
        }
        
        //cout << count << endl;
        //cout << count1 << endl; // 0 or 1
        
        return sign ? 1.0 / result : result;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    cout << "pow(34.00515, -3): " << sol.myPow(34.00515, -3) << endl;
    cout << "pow(2, -3): " << sol.myPow(2, -3) << endl;
    cout << "pow(-2, 3): " << sol.myPow(-2, 3) << endl;
    cout << "pow(1, INT_MAX): " << sol.myPow(1, INT_MAX-1) << endl;
    cout << "pow(-1, INT_MAX): " << sol.myPow(-1, INT_MAX) << endl;
    cout << "pow(2, INT_MAX): " << sol.myPow(2, INT_MAX) << endl;
    cout << "pow(-2, INT_MAX): " << sol.myPow(-2, INT_MAX) << endl;
    
    //cout << "pow(34.00515, -3): " << sol.myPow1(34.00515, -3) << endl;
    //cout << "pow(2, -3): " << sol.myPow1(2, -3) << endl;
    //cout << "pow(-2, 3): " << sol.myPow1(-2, 3) << endl;
    //cout << "pow(1, INT_MAX): " << sol.myPow1(1, INT_MAX-1) << endl;
    //cout << "pow(-1, INT_MAX): " << sol.myPow1(-1, INT_MAX) << endl;
    //cout << "pow(2, INT_MAX): " << sol.myPow1(2, INT_MAX) << endl;
    //cout << "pow(-2, INT_MAX): " << sol.myPow1(-2, INT_MAX) << endl;

    return 0;
}
