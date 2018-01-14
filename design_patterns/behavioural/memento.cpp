#include <iostream>
#include <string>

using namespace std;


class EditorMemento {
string content;

public:
    EditorMemento(const string & content) : content (content) {}

    string getContent() const {
        return content;
    }
};

class Editor {
string content;

public:
    void type(const string & text) {
        content += text;
    }

    string getContent() {
        return content;
    }

    EditorMemento save() {
        return EditorMemento(content);
    }

    void restore(const EditorMemento & memento) {
        content = memento.getContent();
    }
};

int main() {
    Editor editor;

    editor.type("Sentence 1");
    editor.type("Sentence 2");

    EditorMemento m = editor.save();

    editor.type("Sentence3");
    cout << "Before restore: " << editor.getContent() << endl;

    editor.restore(m);
    cout << "After restore: " << editor.getContent() << endl;
}
