#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;
};
 
Node* createNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = nullptr;
    return n;
}
 
void insertAtEnd(Node*& head, int val) {
    Node* n = createNode(val);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}
 
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}
 
Node* rearrangeEvenOdd(Node* head) {
    if (!head) return head;
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        temp->next = nullptr;
        if (temp->data % 2 == 0) {
            if (!evenHead) {
                evenHead = temp;
                evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }
        } else {
            if (!oddHead) {
                oddHead = temp;
                oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = nextNode;
    }
    if (!evenHead) return oddHead;
    evenTail->next = oddHead;
    return evenHead;
}
 
int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Original list: ";
    printList(head);
    head = rearrangeEvenOdd(head);
    cout << "Modified list: ";
    printList(head);
    return 0;
}
