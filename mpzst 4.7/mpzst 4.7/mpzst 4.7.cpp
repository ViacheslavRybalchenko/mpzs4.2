#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

int longestValidParentheses(std::string s) {
    std::stack<int> st;
    st.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            }
            else {
                maxLength = std::max(maxLength, i - st.top());
            }
        }
    }
    return maxLength;
}

int main() {
    setupConsole();
    std::cout << "--- Çàâäàííÿ 7: Íàéäîâø³ ä³éñí³ äóæêè ---" << std::endl;

    std::string s1 = "(()";
    std::cout << "Âõ³ä: " << s1 << std::endl;
    std::cout << "Âèâ³ä: " << longestValidParentheses(s1) << std::endl;

    std::string s2 = ")()())";
    std::cout << "Âõ³ä: " << s2 << std::endl;
    std::cout << "Âèâ³ä: " << longestValidParentheses(s2) << std::endl;

    std::string s3 = "";
    std::cout << "Âõ³ä: " << s3 << std::endl;
    std::cout << "Âèâ³ä: " << longestValidParentheses(s3) << std::endl;

    return 0;
}