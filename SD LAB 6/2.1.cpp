using namespace std;
#include <iostream>
#include <string>


class Node                      //lista
{
public:
    string* data;
    Node* next;
    int size=0;                     //size of table[i]
};

void ListInsert(Node* &node, string new_data,int &nr)           //inserare la stanga
{   
    nr++;
    Node* new_node = new Node();
    new_node->data = new string();
    *new_node->data = new_data;
    new_node->next = node;
    new_node->size = nr;
    node = new_node;
}

void reduce(Node* node) {           //pt eliminare ,size-- la toate elementele din table[i] , primul element di lista are size-ul adevarat al lui table[i]
    while (node != NULL)
    {
        node->size--;
        node = node->next;
    }
}

void del_elem(string x, Node*& node) {
        reduce(node);
    if (node == NULL) {
        cout << "Lista nu are elemente" << endl;
        return;
    }
    Node* prev = NULL;
    Node* aux = node;
    if (x == (*node->data)) {               //daca nodul head are el insusi valoarea
        node = aux->next;
        delete aux;
        cout << "Valoarea a fost eliminata" << endl;;
        return;
    }
    while (aux != NULL && (*aux->data) != x) {      //cautam x , tinem minte nodul previzoriu
        prev = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        cout << "Valoarea nu exista in lista" << endl;
        return;
    }
    prev->next = aux->next;             //suntem pe x , nodul previzoriu va pointa la nodul curent->next , nod curent fiind x
    delete aux;
    cout << "Valoarea a fost eliminata" << endl;;
    return;
}

class Hash
{
    int capacity;
    Node** table;
public:
    Hash(int x) {
        this->capacity = x;
        table = new Node* [capacity];
        for (int i = 0; i < capacity; i++)              
            table[i] = new Node;
    }

    void HashInsert(string nume) {
        int index = HashFunction(nume);
        int nr = 0;
        if (table[index]->size != 0)
            nr = table[index]->size;
        ListInsert(table[index], nume,nr);
    }

    int HashFunction(string x) {
        return (x.length() % capacity);
    }

    void HashDelete(string nume) {
        int index = HashFunction(nume);
        del_elem(nume, table[index]);
    };

    void PrintHash() {
        for (int i = 0; i < capacity; i++) {
            cout << i << " ---> ";
            int j = 0;
            if (table[i]==nullptr) {                //daca nu aveam nimic in cheia i
                cout << endl;
            }
            else {
                for (Node* a = table[i]; j < table[i]->size; a = a->next, j++)
                    cout << (*a->data)<<" ";
                cout << endl;
            }
        }
    }

    void Search(string nume) {
        int index = HashFunction(nume);
        for (Node* i = table[index]; i->next != NULL; i = i->next) {
            if ((*i->data) == nume) {
                cout << "Studentul exista";
                return;
            }
        }
        cout << "Studentul nu exista";
    }
};

int main()
{
    string a[] = { "matei","barbu","paul","sec","stefan","costinel","simon","nikita","radu" };
    int n = sizeof(a) / sizeof(a[0]);
    Hash h(5);
    for (int i = 0; i < n; i++)
        h.HashInsert(a[i]);
    h.PrintHash();
    cout << endl;
    h.HashDelete(a[1]);
    h.PrintHash();
    h.Search(a[3]);
    return 0;
}

