#include <iostream>
#include<queue>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
Node* GetNewNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(Node* root, char data) {
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
void LevelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node* current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
void PostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data;
}
void PreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    InOrder(root->left);
    cout << root->data;
    InOrder(root->right);
}
int main() {
    Node* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
    LevelOrder(root);
    return 0;
}