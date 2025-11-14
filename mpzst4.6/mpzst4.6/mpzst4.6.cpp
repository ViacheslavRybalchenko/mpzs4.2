#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>
#include <string>
#include <stack>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<long> s;
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            long b = s.top(); s.pop();
            long a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
        else {
            s.push(std::stol(token));
        }
    }
    return s.top();
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 6: Зворотна польська нотація ---" << std::endl;

    std::vector<std::string> tokens1 = { "2", "1", "+", "3", "*" };
    std::cout << "Вхід: [\"2\",\"1\",\"+\",\"3\",\"*\"]" << std::endl;
    std::cout << "Вивід: " << evalRPN(tokens1) << std::endl;

    std::vector<std::string> tokens2 = { "4", "13", "5", "/", "+" };
    std::cout << "Вхід: [\"4\",\"13\",\"5\",\"/\",\"+\"]" << std::endl;
    std::cout << "Вивід: " << evalRPN(tokens2) << std::endl;

    return 0;
}