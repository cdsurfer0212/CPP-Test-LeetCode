//
//  longestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by Sean Zeng on 7/28/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

/**
 * Given a string, find the length of the longest substring without repeating characters.

 * Examples:

 * Given "abcabcbb", the answer is "abc", which the length is 3.

 * Given "bbbbb", the answer is "b", with the length of 1.

 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#import <iostream>
#import <map>
#import <string>

using namespace std;

class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int prevRepeatPos = -1;
        map<char, int> m;
        
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end() && m[s[i]] > prevRepeatPos) {
                prevRepeatPos = m[s[i]];
            }
            
            if (i - prevRepeatPos > maxLen) {
                maxLen = i - prevRepeatPos;
            }
            
            m[s[i]] = i;
        }
        
        return maxLen;
    }
    */

    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int prevRepeatPos = -1;
        int a[256]; // ASCII
        memset(a, -1, sizeof(a));
        
        for (int i = 0; i < s.size(); i++) {
            if (a[(unsigned)s[i]] != -1 && a[(unsigned)s[i]] > prevRepeatPos) {
                prevRepeatPos = a[(unsigned)s[i]];
            }
            
            if (i - prevRepeatPos > maxLen) {
                maxLen = i - prevRepeatPos;
            }
            
            a[(unsigned)s[i]] = i;
        }

        return maxLen;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    string s = "abcabcbb";
    cout << s << ": " << sol.lengthOfLongestSubstring(s) << endl;
    
    s = "bbbbb";
    cout << s << ": " << sol.lengthOfLongestSubstring(s) << endl;
    
    s = "pwwkew";
    cout << s << ": " << sol.lengthOfLongestSubstring(s) << endl;
    
    s = "bbabcdb";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;
    
    s = "abba";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}