//https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

#include <fstream>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
};

int max(int a, int b) 
{
    if (a < b)
        return b;
    else
        return a;
}

int height(Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int value)
{
    Node* node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;

    return y;
}

int getBalance(Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int value)
{
    if (node == NULL)
        return(newNode(value));

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left),
        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printSRD(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printSRD(root->left);
        printSRD(root->right);
    }
}

int main()
{
    Node* root = NULL;
    ifstream f("D:\\Tools\\Visual Studio Community\\Projects\\SD Laborator 5\\arbore.in");
    int a;
    while (f >> a) {;
        root = insert(root, a);
    }
    printSRD(root);
    f.close();

    return 0;
}