#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNMarkers(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '0'));
        
        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        
        backtrack(0, n, board, cols, diag1, diag2, result);
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag1,
                   unordered_set<int>& diag2,
                   vector<vector<string>>& result) {
        
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
                continue;
            
            board[row][col] = '*';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            backtrack(row + 1, n, board, cols, diag1, diag2, result);
            
            board[row][col] = '0';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};

int main() {
    Solution s;
    int n = 4;
    vector<vector<string>> solutions = s.solveNMarkers(n);
    for (auto& sol : solutions) {
        for (auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
