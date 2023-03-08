#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* newNode(int value) {
    struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
    aux->data = value;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

struct Node* insert(struct Node* node, int value) {
    if (node == NULL)
        return newNode(value);
    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return node;
}

Node* LCA(Node* root, int n1, int n2)
{
    if (root == NULL) 
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;
}

int main()
{
    struct Node* root = NULL;
    int x;
    cout << "Nr de elemente : ";
    cin >> x;
    int k = 0;
    cout << endl;
    cout << "Elementele arborelui : ";
    while (k < x) {
        int a;
        cin >> a;
        root = insert(root, a);
        k++;
    }
    while (root!=NULL) {
        cout << endl << "Nod1 = ";
        int a,b;
        cin >> a;
        cout << "Nod2 = ";
        cin >> b;
        cout << endl;
        Node* aux = LCA(root, a, b);
        cout << "LCA = " << aux->data << endl;
    }
    return 0;
}