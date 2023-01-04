#include <iostream>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
bool isSubtreeGreater(BstNode* root, int value) {
    if (root == NULL) {
        return true;
    }
    if (root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) {
        return true;
    }
    else
        return false;
}
bool isSubtreeLesser(BstNode* root, int value) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) {
        return true;
    }
    else
        return false;
}
int FindMin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty.";
        return -1;
    }
    else if (root->left == NULL) {
        return root->data;
    }
    return FindMin(root->left);
}
int FindMax(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty.";
        return -1;;
    }
    else if (root->right == NULL) {
        return root->data;
    }
    return FindMin(root->right);
}

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search(BstNode* root, int data) {
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else 
        return Search(root->right, data);
}
bool IsBinarySearchTree(BstNode* root) {
    if (root == NULL) {
        return true;
    }
    if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right)) {
        return true;
    }
    else
        return false;
}
int main() {
    BstNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    
    cout << IsBinarySearchTree(root);
    return 0;
}