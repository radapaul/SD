#include <iostream>
#include <string>
using namespace std;

struct Node {
    string* data;
    struct Node* right;
    struct Node* left;
};

struct Node* newNode(string value) {
    struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
    aux->data = new string();
    *aux->data = value;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

struct Node* insert(struct Node* node, string value) {
    if (node == NULL)
        return newNode(value);
    if (value < *node->data)
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
    cout << *node->data << " ";
    printSRD(node->right);
}

int main()
{
    struct Node* root = NULL;
    string s;
    cout << "Sirul de cuvinte : ";
    getline(cin, s);
    cout << endl;
    string temp = "";
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || i == s.length()) {
            if (i != 0 && s[i - 1] != ' ')
                root = insert(root, temp);
            temp = "";
        }
        else {
            temp += s[i];
        }
    }
    printSRD(root);
    cout << endl;
    return 0;
}