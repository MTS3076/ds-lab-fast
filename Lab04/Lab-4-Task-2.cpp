#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;
};
 
class CircularList {
private:
    Node* head;
 
public:
    CircularList() {
        head = nullptr;
    }
 
    void insertAtEnd(int val) {
        Node* n = new Node();
        n->data = val;
        n->next = nullptr;
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }
 
    void insertAtBeginning(int val) {
        Node* n = new Node();
        n->data = val;
        n->next = nullptr;
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }
 
    void insertAtPosition(int pos, int val) {
        if (pos <= 0 || !head) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        int i = 0;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        Node* n = new Node();
        n->data = val;
        n->next = temp->next;
        temp->next = n;
    }
 
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            Node* last = head;
            while (last->next != head) last = last->next;
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != head) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
 
    void printList() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};
 
int main() {
    CircularList list;
    int choice;
    do {
        cout << "1.Insert End 2.Insert Beginning 3.Insert Position 4.Delete Node 5.Print 0.Exit\n";
        cin >> choice;
        int val, pos;
        if (choice == 1) {
            cin >> val;
            list.insertAtEnd(val);
        } else if (choice == 2) {
            cin >> val;
            list.insertAtBeginning(val);
        } else if (choice == 3) {
            cin >> pos >> val;
            list.insertAtPosition(pos, val);
        } else if (choice == 4) {
            cin >> val;
            list.deleteNode(val);
        } else if (choice == 5) {
            list.printList();
        }
    } while (choice != 0);
    return 0;
}
