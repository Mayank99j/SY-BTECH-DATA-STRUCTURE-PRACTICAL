#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert function (level order)
Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Insert at first empty left
        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        // Insert at first empty right
        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Inorder traversal (just to display)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}