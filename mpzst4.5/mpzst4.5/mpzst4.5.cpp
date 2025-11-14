#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

std::string decodeString(std::string s) {
    std::stack<int> numStack;
    std::stack<std::string> strStack;
    std::string currentStr = "";
    int currentNum = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        }
        else if (std::isalpha(c)) {
            currentStr += c;
        }
        else if (c == '[') {
            numStack.push(currentNum);
            strStack.push(currentStr);
            currentNum = 0;
            currentStr = "";
        }
        else if (c == ']') {
            int k = numStack.top();
            numStack.pop();

            std::string prevStr = strStack.top();
            strStack.pop();

            std::string repeatedStr = "";
            for (int i = 0; i < k; ++i) {
                repeatedStr += currentStr;
            }
            currentStr = prevStr + repeatedStr;
        }
    }
    return currentStr;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 5: Декодувати рядок ---" << std::endl;

    std::string s1 = "3[a]2[bc]";
    std::cout << "Вхід: " << s1 << std::endl;
    std::cout << "Вивід: " << decodeString(s1) << std::endl;

    std::string s2 = "3[a2[c]]";
    std::cout << "Вхід: " << s2 << std::endl;
    std::cout << "Вивід: " << decodeString(s2) << std::endl;

    std::string s3 = "2[abc]3[cd]ef";
    std::cout << "Вхід: " << s3 << std::endl;
    std::cout << "Вивід: " << decodeString(s3) << std::endl;

    return 0;
}