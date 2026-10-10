#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    stack<string> undoStack;
    stack<string> redoStack;
public:
    void type(string word) {
        undoStack.push(word);
        while (!redoStack.empty()) redoStack.pop();
    }
    void undo() {
        if (undoStack.empty()) return;
        redoStack.push(undoStack.top());
        undoStack.pop();
    }
    void redo() {
        if (redoStack.empty()) return;
        undoStack.push(redoStack.top());
        redoStack.pop();
    }
    void print() {
        stack<string> temp = undoStack;
        string s = "";
        while (!temp.empty()) {
            s = temp.top() + (s.empty() ? "" : " ") + s;
            temp.pop();
        }
        cout << "\"" << s << "\"" << endl;
    }
};

int main() {
    TextEditor e;
    e.type("Hello");
    e.print();
    e.type("World");
    e.print();
    e.undo();
    e.print();
    e.redo();
    e.print();
    e.undo();
    e.print();
    e.type("There");
    e.print();
    e.redo();
    e.print();
    return 0;
}
