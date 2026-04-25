#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        initializeBoard();
    }

    void initializeBoard() {
        char ch = '1';
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j] = ch++;
            }
        }
    }

    void displayBoard() {
        cout << "\n";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << " " << board[i][j];
                if(j<2) cout << " |";
            }
            if(i<2) cout << "\n---+---+---\n";
        }
        cout << "\n";
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer=='X') ? 'O' : 'X';
    }

    bool makeMove(int choice) {
        int row = (choice-1)/3;
        int col = (choice-1)%3;

        if(board[row][col] != 'X' && board[row][col] != 'O'){
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        // Rows & Columns
        for(int i=0;i<3;i++){
            if(board[i][0]==currentPlayer &&
               board[i][1]==currentPlayer &&
               board[i][2]==currentPlayer)
               return true;

            if(board[0][i]==currentPlayer &&
               board[1][i]==currentPlayer &&
               board[2][i]==currentPlayer)
               return true;
        }

        // Diagonals
        if(board[0][0]==currentPlayer &&
           board[1][1]==currentPlayer &&
           board[2][2]==currentPlayer)
           return true;

        if(board[0][2]==currentPlayer &&
           board[1][1]==currentPlayer &&
           board[2][0]==currentPlayer)
           return true;

        return false;
    }

    bool checkDraw() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    void playGame() {
        int choice;

        while(true) {
            displayBoard();
            cout << "Player " << currentPlayer 
                 << ", enter position (1-9): ";
            cin >> choice;

            if(choice < 1 || choice > 9 || !makeMove(choice)){
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if(checkWin()){
                displayBoard();
                cout << "🎉 Player " << currentPlayer 
                     << " wins!\n";
                break;
            }

            if(checkDraw()){
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}