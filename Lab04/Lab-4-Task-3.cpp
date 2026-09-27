#include <iostream>
using namespace std;
 
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};
 
class CircularDoublyList {
private:
    DNode* head;
 
public:
    CircularDoublyList() {
        head = nullptr;
    }
 
    void insertAtEnd(int val) {
        DNode* n = new DNode();
        n->data = val;
        n->next = nullptr;
        n->prev = nullptr;
        if (!head) {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }
        DNode* last = head->prev;
        last->next = n;
        n->prev = last;
        n->next = head;
        head->prev = n;
    }
 
    void insertAtBeginning(int val) {
        DNode* n = new DNode();
        n->data = val;
        n->next = nullptr;
        n->prev = nullptr;
        if (!head) {
            head = n;
            n->next = n;
            n->prev = n;
            return;
        }
        DNode* last = head->prev;
        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        head = n;
    }
 
    void insertAtPosition(int pos, int val) {
        if (pos <= 0 || !head) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        int i = 0;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        DNode* n = new DNode();
        n->data = val;
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
 
    void deleteNode(int val) {
        if (!head) return;
        DNode* curr = head;
        do {
            if (curr->data == val) {
                if (curr->next == curr) {
                    delete curr;
                    head = nullptr;
                    return;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head) head = curr->next;
                delete curr;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }
 
    void printList() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        DNode* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};
 
int main() {
    CircularDoublyList list;
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
