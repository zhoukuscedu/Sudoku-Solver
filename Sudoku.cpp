#include "Sudoku.h"

SudokuBoard::SudokuBoard()
    :board(9,vector<char>(9))
{
}

void SudokuBoard::createBoard(){
    cout << "PROMPT: Please Enter Board Values" << endl;
    char c;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> c;
            if(c > '0' && c <= '9' || c == '.'){
                board[i][j] = c;
            }
            else{
                cout << "ERROR: Invalid Input" << endl;
                return;
            }
        }
    }
}

void SudokuBoard::printBoard(){
    for(int i = 0; i < board.size(); i++){
        for(int j =0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void SudokuBoard::fillBoard(){{
    for(int i =0; i <board.size(); i++){
        for(int j = 0; j<board.size(); j++){
            board[i][j] = '.';
        }
    }
}}

bool SudokuBoard::isValidSudoku() {
    unordered_map<string, int> num_count;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            string row = "row " + to_string(i) + " ";
            string col = "col " + to_string(j) + " ";
            string box = "box " + to_string(3*(i/3) + j/3) + " ";
            if(board[i][j] != '.'){
                string num = to_string(board[i][j]);
                row += num;
                col += num;
                box += num;

                num_count[row]++;
                num_count[col]++;
                num_count[box]++;
                    
                if(num_count[row] > 1 || num_count[col] > 1 || num_count[box] > 1)
                    return false;
                }
            }
        }
        
    return true;
}

bool SudokuBoard::checkMove(int row , int col, char c) {
	for (int i = 0; i < 9; i++)
		if (board[row][i] == c) return false;
	for (int j = 0; j < 9; j++)
		if (board[j][col] == c) return false;
	for (int i = 0; i < 3; i++)
	    for (int j = 0; j < 3; j++)
			if (board[row / 3 * 3 + i][col / 3 * 3 + j] == c)
				return false;
	return true;
}

bool SudokuBoard::solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){        
            if(board[i][j] == '.'){       
                for(int k = 1; k <=9; k ++){        
                    if(checkMove(i, j, '0'+k)){        
                        board[i][j] = '0' + k;
                        if(solve()) return true;
                            board[i][j] = '.';
                    }
                }
                return false; //no possible placement
            }
        }
    }
    return true;
}    
    
void SudokuBoard::solveSudoku() {
        solve();
}
