#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <stack>
#include <algorithm>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

class MinStack {
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    setupConsole();
    std::cout << "--- Завдання 3: Мінімальний стек ---" << std::endl;

    MinStack minStack;
    minStack.push(-2);
    std::cout << "push(-2)" << std::endl;
    minStack.push(0);
    std::cout << "push(0)" << std::endl;
    minStack.push(-3);
    std::cout << "push(-3)" << std::endl;
    std::cout << "getMin(): " << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << "pop()" << std::endl;
    std::cout << "top(): " << minStack.top() << std::endl;
    std::cout << "getMin(): " << minStack.getMin() << std::endl;

    return 0;
}