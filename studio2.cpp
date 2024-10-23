#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int rollDice() {
    return(rand() % 6 + 1) + (rand() % 6 + 1) ;
}

int playGame() {
    int position = 1;
    int moves = 0;

    while (position < 50) {
        int roll = rollDice();
        cout << "Rolling: " << roll << endl;
        position += roll;
        
        if (position % 6 == 0) {
            cout << " You climbed a ladder!" << endl;
            position += 3;
        } 
        else if (position % 7 == 0) {
            cout << " You fell down a chute!" << endl;
            position -= 3;
        }

        if(position == 1 || position == 22 || position == 33) {
            cout << "You returned to the start!" << endl;
            position = 1;
        }

        cout << " Your position is now " << position << endl;
        moves++;
    }

    return moves;
}

int main() {
    srand(time(0));

    int playerCount = 4;
    int bestMoves = 1000;
    int winningPlayer = -1;

    for (int player = 1; player <= playerCount; player++) {
        cout << "\nPlayer " << player << "'s turn\n";
        int moves = playGame();
        cout << " You finished in " << moves << " moves\n";

        if(moves < bestMoves) {
            bestMoves = moves;
            winningPlayer = player;
        }
    }

    cout << "\nCongratulations Player " << winningPlayer << ", you win with " << bestMoves << " moves!\n";

    return 0;
}
            