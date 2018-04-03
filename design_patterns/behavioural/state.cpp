#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class WritingState {
public:
    virtual void write(const string & word) =0;
};

class UpperCase : public WritingState {
public:
    void write(const string & word) {
        string w = word;
        transform(w.begin(), w.end(), w.begin(), ::toupper);
        cout << w << endl;
    }
};

class Default : public WritingState {
public:
    void write(const string & word) {
        cout << word << endl;
    }
};

class TextEditor {
WritingState * state;
public:
    TextEditor() : state(new Default()) {}
    void setState(WritingState * state) {
        this->state = state;
    }

    void type(const string & text) {
        state->write(text);
    }
};

int main() {
    TextEditor editor;
    editor.type("Hello World");
    editor.setState(new UpperCase());
    editor.type("Hello World");
}