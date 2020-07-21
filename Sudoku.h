#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SudokuBoard{
    public:
        SudokuBoard();

        void createBoard();
        void printBoard();
        void fillBoard();

        bool isValidSudoku();
        bool checkMove(int row , int col, char c);
        bool solve();
        void solveSudoku();
        
    private:
        vector<vector<char>> board;
};