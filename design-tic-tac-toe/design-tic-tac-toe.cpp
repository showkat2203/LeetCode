class TicTacToe {
public:

    char board[101][101];
    char playerMark[2] = {'x', 'o'};
    int nn;

    TicTacToe(int n) {
        nn = n;
    }
    
    int move(int row, int col, int player) {
        return markBoard(row, col, player);
    }

    int markBoard(int r, int c, int player) {
        board[r][c] = playerMark[player-1];
        if(isWon(board[r][c])) return player;
        else return 0;
    }

    bool isWon(char mark) {
        return isHorizontallySame(mark) || isVerticallySame(mark) || isDiagonallySame(mark);
    }

    bool isHorizontallySame(char mark) {
        for(int i=0; i<nn; i++) {
            bool isSame = true;
            for(int j=0; j<nn; j++) {
                if(board[i][j] != mark) {isSame = false; break;}
            }
            if(isSame) return true;
        }
        return false;
    }

    bool isVerticallySame(char mark) {
        for(int i=0; i<nn; i++) {
            bool isSame = true;
            for(int j=0; j<nn; j++) {
                if(board[j][i] != mark) {isSame = false; break;}
            }
            if(isSame) return true;
        }
        return false;
    }

    bool isDiagonallySame(char mark) {
        int r=0, c=0;
        bool isSame = true;
        while(r<nn) {
            if(board[r][c] != mark) {isSame = false; break;}
            r++;
            c++;
        }
        if(isSame) return true;

        r = 0, c = nn-1;
        isSame = true;
        while(r<nn) {
            if(board[r][c] != mark) {isSame = false; break;}
            r++;
            c--;
        }
        if(isSame) return true;
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */