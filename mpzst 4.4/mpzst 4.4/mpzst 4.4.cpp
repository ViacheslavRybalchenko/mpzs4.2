#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <stack>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        transfer();
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        transfer();
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    setupConsole();
    std::cout << std::boolalpha;
    std::cout << "--- Завдання 4: Черга зі стеків ---" << std::endl;

    MyQueue myQueue;
    std::cout << "Чергу створено" << std::endl;
    myQueue.push(1);
    std::cout << "push(1)" << std::endl;
    myQueue.push(2);
    std::cout << "push(2)" << std::endl;
    std::cout << "peek(): " << myQueue.peek() << std::endl;
    std::cout << "pop(): " << myQueue.pop() << std::endl;
    std::cout << "empty(): " << myQueue.empty() << std::endl;

    return 0;
}