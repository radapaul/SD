//Exercitiul 1 - Coadă cu priorităti. (2.5p) O coadă cu priorităti este o coadă în care
//elementele au, pe lângă cheie şi o prioritate.Vom presupune că cea mai înaltă prioritate este
//1, urmată de 2 etc.Ordinea liniară este dată de regulile :
//• elementele cu aceeaşi prioritate sunt extrase(şi procesate) în ordinea intrării;
//• toate elementele cu prioritate i se află înaintea celor cu prioritate i + 1 (şi deci vor fi
//    extrase înaintea lor).
//    Implementati operatiile de inserare si de stergere pentru acest tip de structură.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    int prio;
};

void push(int x, Node*& node, int p) {
    Node* start = node;
    if (node == NULL) {
        Node* new_node = new Node;
        new_node->data = x;
        new_node->next = NULL;
        new_node->prio = p;
        node = new_node;
        return;
    }
    if (p == node->prio && node->next==NULL) {          //daca e un singur nod
        Node* new_node = new Node;
        new_node->next = node->next;
        new_node->prio = p;
        new_node->data = node->data;
        node->data = x;
        node->next = new_node;
        return;
    }
    while (node != NULL) {
        if (p == node->prio) {
            Node* new_node = new Node;
            new_node->next = node->next;
            new_node->prio = p;
            new_node->data = node->data;
            node->data = x;
            node->next = new_node;
            node = start;
            return;
        }
        if ((p < node->prio) && (node->next=NULL)) {
            Node* new_node = new Node;
            new_node->next = NULL;
            new_node->prio = p;
            new_node->data = x;
            node->next = new_node;
            node = start;
            return;
        }
        if (p < node->prio) {
            Node* new_node = new Node;
            new_node->next = node->next;
            new_node->prio = p;
            new_node->data = x;
            node->next = new_node;
            node = start;
            return;
        }
        node = node->next;
    }
    node = start;
    while(node->next!=NULL) {
        node = node->next;
    }
    if (p > node->prio) {
        Node* new_node = new Node;
        new_node->next = NULL;
        new_node->prio = p;
        new_node->data = x;
        node->next = new_node;
        node = start;
        return;
    }
    Node* new_node = new Node;
    new_node->next = NULL;
    new_node->prio = p;
    new_node->data = x;
    node->next = new_node;
    return;
}

void pop(Node*& node) {
    Node* aux = node;
    Node* prev = NULL;
    while (aux->next != NULL) {
        prev = aux;
        aux = aux->next;
    }
    prev->next = aux->next;
    delete aux;
    return;
}

void print(Node* node) {
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void menu() {
    Node* node = NULL;
    int x = 0;
    cout << "1 - Push" << endl;
    cout << "2 - Pop" << endl;
    cout << "3 - Afisare lista" << endl;
    cout << "4 - Exit" << endl;
    while (x != 4) {
        cout << "Input : ";
        cin >> x;
        if (x == 1) {
                int a,p;
                cout << "Valoare : ";
                cin >> a;
                cout << "Prioritate : ";
                cin >> p;
                push(a, node,p);
            }
        if (x == 2) {
            pop(node);
        }
        if (x == 3) {
            print(node);
            cout << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}

