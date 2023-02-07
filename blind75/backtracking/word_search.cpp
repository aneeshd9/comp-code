#include <vector>
#include <string>

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board[0].size(); ++c) {
        if (board[r][c] == word[0]) {
          if (search(board, word, 0, r, c)) return true;
        }
      }
    }
    return false;
  }

  bool search(std::vector<std::vector<char>> &board,
              std::string word,
              int wordIndex,
              int i,
              int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[wordIndex]) {
      return false;
    }

    if (wordIndex == word.size() - 1) {
      return true;
    }

    board[i][j] = '$';

    if (search(board, word, wordIndex + 1, i + 1, j) ||
        search(board, word, wordIndex + 1, i - 1, j) ||
        search(board, word, wordIndex + 1, i, j + 1) ||
        search(board, word, wordIndex + 1, i, j - 1)) {
      return true;
    }

    board[i][j] = word[wordIndex];
    return false;
  }
};
