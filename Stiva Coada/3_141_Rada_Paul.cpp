#include <iostream>
using namespace std;

class Stack {
public:
    int data;
    Stack* next;
};

Stack* top = NULL;

void push(int x) {
    Stack* new_node = new Stack;
    new_node->data = x;
    new_node->next = top;
    top = new_node;
    return;
}

void pop() {
    if (top == nullptr) {
        cout << "Stiva este deja goala";
        return;
    }
    top = top->next;
    return;
}

int check(int x) {
    while (top != NULL) {
        if (top->data == x)
            return 1;
        top = top->next;
    }
    return 0;
}

int main()
{
    int n, v[100],i;
    cout << "N = ";
    cin >> n;
    cout << "Lista perechi : ";
    for (i = 0;i < n;i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    push(v[0]);
    for (i = 1;i < n;i++) {
        if (check(v[i]) == 1)
            pop();
        else
            push(v[i]);
    }
    if (top == nullptr)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}

