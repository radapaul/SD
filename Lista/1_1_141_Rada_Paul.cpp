//1.1.  Să se creeze o listă ordonată crescător folosind operatii de insertie (nodul Head va retine elementul minim).
//1.2.  Implementati operatia de stergere a întregii liste
//1.3.  Implementati operatia de stergere a unui element dat la tastatură dintr-o listă înlăntuită oarecare(dacă el există).
//Rezolvarea exercitiilor 1_1, 1_2, 1_3 se va realiza în 3 functii apelate dintr-un acelasi fisier

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void insert(int x, Node*& node) {
	Node* start = node;
	if (node == NULL) {
		Node* new_node = new Node;
		new_node->data = x;
		new_node->next = node;
		node = new_node;
		return;
	}
	while (node != NULL) {
		if (node == start && x < node->data) {
			int aux = node->data;
			node->data = x;
			x = aux;
		}
		if (node->next == NULL) {
			Node* new_node = new Node;
			new_node->data = x;
			new_node->next = NULL;
			node->next = new_node;
			node = start;
			return;
		}
		if (x < node->next->data) {
			Node* new_node = new Node;
			new_node->data = x;
			new_node->next = node->next;
			node->next = new_node;
			node = start;
			return;
		}
		node = node->next;
	}
	node = start;
	return;
}

void del_list(Node*& node) {
	while (node != NULL) {
		Node* temp;
		temp = node->next;
		delete node;
		node = temp;
	}
}

void del_elem(int x, Node*& node) {
	if (node == NULL) {
		cout << "Lista nu are elemente" << endl;
		return;
	}
	Node* prev = NULL;
	Node* aux = node;
	if (x == node->data) {
		node = aux->next;
		delete aux;
		cout << "Valoarea a fost eliminata" << endl;;
		return;
	}
	while (aux != NULL && aux->data != x) {
		prev = aux;
		aux = aux->next;
	}
	if (aux == NULL) {
		cout << "Valoarea nu exista in lista" << endl;
		return;
	}
	prev->next = aux->next;
	delete aux;
	cout << "Valoarea a fost eliminata" << endl;;
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
	int x = 0, k;
	cout << "1 - Creare lista" << endl;
	cout << "2 - Stergere lista" << endl;
	cout << "3 - Stergere element din lista" << endl;
	cout << "4 - Afisare lista" << endl;
	cout << "5 - Exit" << endl;
	while (x != 5) {
		cout << "Input : ";
		cin >> x;
		if (x == 1) {
			cout << "Numar de elemente : ";
			cin >> k;
			cout << "Elementele listei : ";
			for (int j = 0; j < k; j++) {
				int a;
				cin >> a;
				insert(a, node);
			}
		}
		if (x == 2) {
			del_list(node);
			cout << "Lista a fost stearsa" << endl;
		}
		if (x == 3) {
			cout << "Valoarea care va fi eliminata din lista : ";
			cin >> k;
			del_elem(k, node);
		}
		if (x == 4) {
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