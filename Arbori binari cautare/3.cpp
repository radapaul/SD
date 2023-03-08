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

void printSRD(struct Node* node,int a,int b)
{
    if (node == NULL)
        return;
    printSRD(node->left,a,b);
    if(node->data <= b && node->data >= a)
        cout << node->data << " ";
    printSRD(node->right,a,b);
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
    cout << endl;
    int k1, k2;
    cout << "K1 = ";
    cin >> k1;
    cout << "K2 = ";
    cin >> k2;
    cout << endl << "Toate cheile cu proprietatea k1 <= x <= k2 :" << endl<<endl;
    printSRD(root, k1, k2);
    cout << endl;
    return 0;
}