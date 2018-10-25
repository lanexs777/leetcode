# 348
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):rowcheck(n), colcheck(n), diag(0), anti(0), total(n) {
       
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add= player==1? 1:-1;
        rowcheck[row]+=add;
        colcheck[col]+=add;
        diag += row==col? add:0;
        anti += row==total-col-1? add:0;
        if(abs(rowcheck[row])==total || abs(colcheck[col])==total || abs(diag)==total || abs(anti)==total)
            return player;
        return 0;
    }

private:
    vector<int> rowcheck;
    vector<int> colcheck;
    int diag, anti;
    int total;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
