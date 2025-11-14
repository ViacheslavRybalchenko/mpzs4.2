#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

bool isValid(std::string s) {
    std::stack<char> st;
    std::unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (map.find(c) == map.end()) {
            st.push(c);
        }
        else {
            if (st.empty() || st.top() != map[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    setupConsole();
    std::cout << std::boolalpha;
    std::cout << "--- Çàâäàííÿ 1: Âàë³äí³ äóæêè ---" << std::endl;

    std::string s1 = "()";
    std::cout << "Âõ³ä: " << s1 << " | Âèâ³ä: " << isValid(s1) << std::endl;

    std::string s2 = "()[]{}";
    std::cout << "Âõ³ä: " << s2 << " | Âèâ³ä: " << isValid(s2) << std::endl;

    std::string s3 = "(]";
    std::cout << "Âõ³ä: " << s3 << " | Âèâ³ä: " << isValid(s3) << std::endl;

    return 0;
}