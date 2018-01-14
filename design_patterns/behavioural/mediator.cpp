#include <iostream>
#include <string>

using namespace std;

class User;

class ChatRoom {
public:
    static void showMessage(User * user, const string & msg);
};

class User {
    string name;

public:
    User(const string & name) : name(name) {}
    
    string getName() const {
        return name;
    }

    void sendMessage(const string & msg) {
        ChatRoom::showMessage(this, msg);
    }
};

void ChatRoom::showMessage(User * user, const string & msg) {
    cout << user->getName() << " says: " << msg << endl;
}


int main() {
    User alice("Alice");
    User bob("Bob");

    alice.sendMessage("Hi there");
    bob.sendMessage("Hello");
}