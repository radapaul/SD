#include <iostream>
using namespace std;

struct NodeVal {
    int data;
    struct NodeVal* next;
};

struct NodeVal* topVal = NULL;

void pushVal(int val) {
    struct NodeVal* new_node = (struct NodeVal*)malloc(sizeof(struct NodeVal));
    new_node->data = val;
    new_node->next = topVal;
    topVal = new_node;
}
void popVal() {
    if (topVal != nullptr)
        topVal = topVal->next;
    else
        return;
}

struct NodeOp {
    char data;
    struct NodeOp* next;
};

struct NodeOp* topOp = NULL;

void pushOp(char op) {
    struct NodeOp* new_node = (struct NodeOp*)malloc(sizeof(struct NodeOp));
    new_node->data = op;
    new_node->next = topOp;
    topOp = new_node;
}
void popOp() {
    if (topOp != nullptr)
        topOp = topOp->next;
    else
        return;
}

int precedent(char op) {
    if (op == '-' || op == '+'){
        return 1;
    }
    return 0;
}

int Operatie(int a, int b, char op) {
    if (op == '-') {
        return a - b;
    }
    if (op == '+') {
        return a + b;
    }
}

int calculare(string input) {
    int i;
    for (i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            continue;
        }
        if (input[i] == '(') {
            pushOp(input[i]);
        }
        else if (isdigit(input[i])) {
            int nr = 0;
            while (i < input.length() && isdigit(input[i]))
            {
                nr = nr * 10 + (input[i] - '0');
                i++;
            }
            pushVal(nr);
            i--;
        }
        else if (input[i] == ')')
        {
            while (topOp != NULL && topOp->data != '(')
            {
                int val2 = topVal->data;
                popVal();
                int val1 = topVal->data;
                popVal();
                char op = topOp->data;
                popOp();
                pushVal(Operatie(val1, val2, op));
            }
            if (topOp != NULL) {
                popOp;
            }
        }
        else
        {
            while (topOp != NULL && precedent(topOp->data) >= precedent(input[i])) {
                int val2 = topVal->data;
                popVal();
                int val1 = topVal->data;
                popVal();
                char op = topOp->data;
                popOp();
                pushVal(Operatie(val1, val2, op));
            }
            pushOp(input[i]);
        }
    }
    while (topOp != NULL) {
        int val2 = topVal->data;
        popVal();
        int val1 = topVal->data;
        popVal();
        if (topOp != nullptr && (topOp->data == '(')) {
            popOp();
        }
        char op = topOp->data;
            popOp();
        if (topOp!=nullptr && (topOp->data == '(')){
            popOp();
        }
        pushVal(Operatie(val1, val2, op));
    }
    return topVal->data;
}

int main() {
    string x;
    cout << "Ecuatia : ";
    cin >> x;
    cout << "Rezultatul este : " << calculare(x);
    /*cout << calculare("(1+(4+5+2)-3)+(6+8)");*/
    return 0;
}

//nu merge pentru "-" ca operatie unara
//inspirat de pe https://www.geeksforgeeks.org/expression-evaluation/
//inteleg daca nu este de punctat