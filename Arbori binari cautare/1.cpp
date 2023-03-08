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

void printSDR(struct Node* node)
{
    if (node == NULL)
        return;
    printSDR(node->left);
    printSDR(node->right);
    cout << node->data << " ";
    return;
}

void printSRD(struct Node* node)
{
    if (node == NULL)
        return;
    printSRD(node->left);
    cout << node->data << " ";
    printSRD(node->right);
}

void printRSD(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printRSD(node->left);
    printRSD(node->right);
}

int main()
{
    int x;                              //x=7
    cout << "Nr de elemente: ";
    cin >> x;
    struct Node* root = NULL;
    int k=0;
    cout << endl;
    cout << "Elementele: ";             //5 3 2 4 7 6 8
    while (k < x) {
        int a;
        cin >> a;
        root = insert(root,a);
        k++;
    }

    cout << endl << "Pre-ordine(RSD)" << endl;
    printRSD(root);
    cout << endl;
    cout << endl << "In-ordine(SRD)" << endl;
    printSRD(root);
    cout << endl;
    cout << endl << "Post-ordine(SDR)" << endl;
    printSDR(root);
    cout << endl;
    return 0;
}