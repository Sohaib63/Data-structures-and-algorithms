#include <iostream>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* FindMin(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty.";
        root->data = -1;
        return root;
    }
    else if (root->left == NULL) {
        return root;
    }
    return FindMin(root->left);
}
BstNode* FindMax(BstNode* root) {
    if (root == NULL) {
        cout << "Error: Tree is empty.";
        root->data = -1;
        return root;
    }
    else if (root->right == NULL) {
        return root;
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
BstNode* Delete(BstNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
        }
        else if (root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
int main() {
    BstNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int number;
    cout << "Enter number to be searched: ";
    cin >> number;
    if (Search(root, number) == true) {
        cout << "Found\n";
    }
    else
        cout << "Not Found\n";
    return 0;
}