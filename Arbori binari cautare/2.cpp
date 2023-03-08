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

void printSRD(struct Node* node)
{
    if (node == NULL)
        return;
    printSRD(node->left);
    cout << node->data << " ";
    printSRD(node->right);
}

struct Node* Next(struct Node* node) {          //urmatorul element in-order
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {                      // daca are un singur copil sau nici unul
        if (root->left == NULL) {
            struct Node* aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL) {
            struct Node* aux = root->left;
            free(root);
            return aux;
        }
        struct Node* aux = Next(root->right);      //pt 2 copii

        root->data = aux->data;         //urmatorul element este pus in locul celui care va fi sters

        root->right = deleteNode(root->right, aux->data);
    }
    return root;
}

int main()
{
    int x;
    cout << "Nr de elemente : ";
    cin >> x;
    struct Node* root = NULL;
    int k = 0;
    cout << endl;
    cout << "Elementele arborelui : ";
    while (k < x) {
        int a;
        cin >> a;
        root = insert(root, a);
        k++;
    }
    while (root != NULL) {
        cout << endl << "Valorea elementului care va fi sters : ";
        int a;
        cin >> a;
        cout << endl;
        root = deleteNode(root, a);
        cout << "Elementele curente ale arborelui : "<<endl<<endl;
        printSRD(root);
        cout << endl;
    }
    return 0;
}