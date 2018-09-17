#36
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //[10] because there are no '0' in the sudoku game only 1~9
        bool row_check[9][10]={ {false} };
        bool col_check[9][10]={ {false} };
        bool grid_check[9][10]={ {false} };
        int d;
        int g;
        
        for(int r=0;r<9;++r) {
            for(int c=0;c<9;++c) {
                if(board[r][c]!='.') {
                    d=board[r][c]-'0';
                    g=( (r/3)*3+(c/3) );
                    if(row_check[r][d]==true || col_check[c][d]==true || grid_check[g][d]==true) {
                        //if appear twice, return false.
                        return false;
                    }
                    // if found it. mark it true.
                    row_check[r][d]=col_check[c][d]=grid_check[g][d]=true;
                    
                }               
            }
        }
        return true;
    }
};
