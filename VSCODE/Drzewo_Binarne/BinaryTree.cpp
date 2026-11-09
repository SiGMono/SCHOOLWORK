#include <iostream>

using namespace std;

// Checks whether every character in the string is a digit.
// Returns true if the whole string is numeric, otherwise false.
bool is_digits(string& str)
{
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

// Represents one node in the binary tree.
// 'w' stores the value of the node,
// while 'left' and 'right' point to its children.
struct Element {
    int w;
    Element* left = nullptr;
    Element* right = nullptr;
};

// Prints the tree in in-order traversal:
// left subtree -> current node -> right subtree.
void write(Element* root) {
    if (root != nullptr) {
        write(root->left);
        cout << root->w << " ";
        write(root->right);
    }
}

// Recursively frees all memory used by the tree rooted at 'n'.
void releaseNode(Element* n)
{
    if (!n) return;
    releaseNode(n->left);
    releaseNode(n->right);
    delete n;
}

int main(void) {
    // A variable for possible user input (not used in the current program).
    string choice;

    // Pointers to the root and the current node during tree construction.
    Element* first;
    Element* current = nullptr;

    // Create the root node with value 1.
    first = new Element;
    current = first;
    current->w = 1;
    current->left = new Element;
    current->right = new Element;

    // Left child of the root: value 2.
    current->left->w = 2;
    // Right child of the root: value 3.
    current->right->w = 3;

    // Move to the left subtree and add two more nodes: 4 and 5.
    current = current->left;
    current->left = new Element;
    current->right = new Element;
    current->left->w = 4;
    current->right->w = 5;

    // Return to the root and go to the right subtree.
    current = first;
    current = current->right;

    // Add two more nodes under the right child: 6 and 7.
    current->left = new Element;
    current->right = new Element;
    current->left->w = 6;
    current->right->w = 7;

    // Print the whole tree.
    current = first;
    write(current);

    // Release the dynamically allocated memory.
    // Note: this program uses a simple recursive cleanup.
    releaseNode(current->left);
    releaseNode(current->right);
    releaseNode(current);

    return 0;
}