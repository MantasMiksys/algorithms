#include <iostream>

using namespace std;

class Game {
virtual void prepare() =0;
virtual void start() =0;
virtual void end() =0;

public:
void play() {
    prepare();
    start();
    end();
}
};

class Football : public Game {
void prepare() {
    cout << "Prepare football" << endl;
}

void start() {
    cout << "Start football" << endl;
}

void end() {
    cout << "Stop football" << endl;
}
};


int main() {
    Game * game = new Football();
    game->play();
}