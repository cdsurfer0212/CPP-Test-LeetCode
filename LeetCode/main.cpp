//
//  main.cpp
//  LeetCode
//
//  Created by Sean Zeng on 6/24/16.
//  Copyright © 2016 Yahoo. All rights reserved.
//

#include <iostream>

extern void usePunctuations();
extern void useDoubleColons();

struct TestStruct
{
    int a;
};

class TestClass
{
public:
    int a;
    int b = 1;
    int foo(int a);
};

int TestClass::foo(int a)
{
    TestClass::a = a;
    return a + TestClass::a + TestClass::b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    useDoubleColons();
    usePunctuations();
    
    return 0;
}

// MARK: use double colons

class TestClass;
namespace TestNamespace
{
    class TestClass {
    public:
        int foo(int a) {
            return a;
        };
    };
    
    void foo() {
        ::TestClass c1;
        printf("%d\n", c1.foo(1)); // 3
        
        TestClass::TestClass c2;
        printf("%d\n", c2.foo(1)); // 1
    }
}

void useDoubleColons()
{
    TestNamespace::foo();
}

// MARK: use punctuations

void usePunctuations()
{
    TestStruct s;
    s.a = 1;
    printf("%d\n", s.a); // 1
    
    TestStruct* ps = new TestStruct();
    ps->a = 2;
    printf("%d\n", (*ps).a); // 2
    
    TestClass c;
    printf("%d\n", c.foo(1)); // 1 + 1 + 1 = 3
    
    TestClass* pc = new TestClass();
    printf("%d\n", pc->foo(2)); // 2 + 2 + 1 = 5
}
