#include <iostream>
#include <queue>
using namespace std;

struct Node {
    string name;
    Node* children[10];
    int childCount;
    Node(string n) {
        name = n;
        childCount = 0;
    }
    void addChild(Node* child) {
        children[childCount++] = child;
    }
};

void printCousins(Node* root, string target) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    bool found = false;

    while (!q.empty()) {
        int size = q.size();
        Node* level[50];
        int levelCount = 0;

        for (int i = 0; i < size; i++) {
            Node* current = q.front(); q.pop();
            bool isParent = false;

            for (int j = 0; j < current->childCount; j++) {
                if (current->children[j]->name == target) {
                    isParent = true;
                    found = true;
                }
            }

            if (!isParent) {
                for (int j = 0; j < current->childCount; j++) {
                    level[levelCount++] = current->children[j];
                }
            }
        }

        if (found) {
            cout << "Cousins of " << target << " are:\n";
            for (int i = 0; i < levelCount; i++) {
                cout << " -> " << level[i]->name << endl;
            }
            return;
        }

        for (int i = 0; i < levelCount; i++) q.push(level[i]);
    }
    cout << "No cousins found.\n";
}

int main() {
    Node* grandFather = new Node("Grandfather");
    Node* father = new Node("Father");
    Node* uncle1 = new Node("Uncle1");
    Node* uncle2 = new Node("Uncle2");
    Node* uncle3 = new Node("Uncle3");

    grandFather->addChild(father);
    grandFather->addChild(uncle1);
    grandFather->addChild(uncle2);
    grandFather->addChild(uncle3);

    father->addChild(new Node("Me"));
    uncle1->addChild(new Node("CousinA"));
    uncle2->addChild(new Node("CousinB"));
    uncle2->addChild(new Node("CousinC"));
    uncle3->addChild(new Node("CousinD"));

    printCousins(grandFather, "Me");
    return 0;
}