#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ValidBoard{
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
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
};

class Solve{
    public:
    bool validate(vector<vector<char>>& board, int row , int col, char c) 
	{
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
    
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(board[i][j] == '.'){
                    
                    for(int k = 1; k <=9; k ++){
                        
                        if(validate(board, i, j, '0'+k)){
                            
                            board[i][j] = '0' + k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; //no possible placement
                }
            }
        }
        return true;
    } 
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


int main(){
    int x;
    cin >> x;
    cout << x;
    return 0;
} 