#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>
#include <functional>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

void inorderHelper(TreeNode* node, std::vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    inorderHelper(node->left, result);
    result.push_back(node->val);
    inorderHelper(node->right, result);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    inorderHelper(root, result);
    return result;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 2: Обхід бінарного дерева в порядку ---" << std::endl;

    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    std::cout << "Вхід: [1,null,2,3]" << std::endl;
    std::vector<int> res1 = inorderTraversal(root1);
    std::cout << "Вивід: ";
    printVector(res1);

    return 0;
}