//Reprezentarea numerelor mari. Se consideră două numere reprezentate într-o listă înlăntuită în care fiecare nod reprezintă o cifră.Cifrele sunt retinute în
//ordine inversă astfel încât cifra unitătilor să fie stocată la începutul listei.Să se scrie un program C / C++ care să calculeze suma acestor numere.
//Exemplu:
//Input: (1 -> 5 -> 3), (2 -> 6 -> 4)
//Output : 813

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};


void adaugare(Node* &head, int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = head;
	head = new_node;
}


void print(Node* node){
	while (node != NULL)
	{
		cout << " " << node->data;
		node = node->next;
	}
}


int main()
{
	Node* node1 = NULL;
	Node* node2 = NULL;

	int x, k, nr1 = 0, nr2 = 0, sum = 0;
	cout << "Nr elemente lista 1 : ";
	cin >> x;
	cout << "Elemente lista 1 : ";
	for (int i = 0;i < x;i++) {
		cin >> k;
		adaugare(node1, k);
	}
	cout << "Lista 1 :";
	print(node1);
	cout << endl;
	cout << "Nr elemente lista 2: ";
	cin >> x;
	cout << "Elemente lista 2 : ";
	for (int i = 0;i < x;i++) {
		cin >> k;
		adaugare(node2, k);
	}
	cout << "Lista 2 :";
	print(node2);
	cout << endl;
	while (node1 != NULL)
	{
		nr1 = nr1 * 10 + node1->data;
		node1 = node1->next;
	}
	cout << "Nr1 = "<< nr1 << endl;
	while (node2 != NULL)
	{
		nr2 = nr2 * 10 + node2->data;
		node2 = node2->next;
	}
	sum = nr1 + nr2;
	cout << "Nr2 = "<< nr2 << endl;
	cout << "Suma numerelor din cele 2 liste este : " << sum<<endl;

	return 0;
}

