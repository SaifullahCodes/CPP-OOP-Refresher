#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node *next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node *top;
public:
    Stack() { top = NULL; }

    void push(char val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // UPDATE: pop() ab delete bhi karega aur character return bhi karega
    char pop() {
        if (top == NULL) return '\0';
        Node *temp = top;
        char val = top->data;
        top = top->next;
        delete temp;
        return val;
    }

    // peek() sirf check karne ke liye (return karega top data)
    char peek() {
        if (top == NULL) return '\0';
        return top->data;
    }

    bool isEmpty() { return top == NULL; }
};

// Referee: Priority check
int getPriority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // 1. Agar letter ya number hai (Quotes added for '0'-'9')
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        // 2. Opening Bracket
        else if (c == '(') {
            s.push(c);
        }
        // 3. Closing Bracket
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // '(' ko nikal do
        }
        // 4. Operator
        else {
            while (!s.isEmpty() && getPriority(s.peek()) >= getPriority(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

int main() {
    string equation = "(A+B)*C-D";
    cout << "Infix:   " << equation << endl;
    cout << "Postfix: " << infixToPostfix(equation) << endl;
    return 0;
}