#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class TrieNode {
public:
  std::vector<int> next;
  bool leaf;

  TrieNode () {
    next = std::vector<int>(26, -1);
    leaf = false;
  }
};

class Solution {
public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {

    trie = std::vector<TrieNode>();
    trie.push_back(TrieNode());

    for (std::string word: words) insert(word);

    int m = board.size();
    int n = board[0].size();
    std::vector<std::vector<bool>> visited (m, std::vector<bool>(n, false));
    std::vector<std::string> ans;
    
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        search(board, i, j, m, n, 0, "", visited, ans);
      }
    }

    return ans;
  }

private:
  std::vector<TrieNode> trie;

  void insert(std::string word) {
    int currentNode = 0;

    for (char ch: word) {
      if (trie[currentNode].next[ch - 'a'] == -1) {
        trie.push_back(TrieNode());
        trie[currentNode].next[ch - 'a'] = trie.size() - 1;
      }
      currentNode = trie[currentNode].next[ch - 'a'];
    }

    trie[currentNode].leaf = true;
  }

  void search(std::vector<std::vector<char>> &board, int i, int j,
              int m, int n, int trieIndex, std::string currentWord,
              std::vector<std::vector<bool>> &visited,
              std::vector<std::string> &ans) {

    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
    if (trie[trieIndex].next[board[i][j] - 'a'] == -1) return;
    trieIndex = trie[trieIndex].next[board[i][j] - 'a'];
    currentWord += board[i][j];
    if (trie[trieIndex].leaf) {
      ans.push_back(currentWord);
      trie[trieIndex].leaf = false; // To find only unique results.
    }

    visited[i][j] = true;
    search(board, i + 1, j, m, n, trieIndex, currentWord, visited, ans);
    search(board, i - 1, j, m, n, trieIndex, currentWord, visited, ans);
    search(board, i, j + 1, m, n, trieIndex, currentWord, visited, ans);
    search(board, i, j - 1, m, n, trieIndex, currentWord, visited, ans);
    visited[i][j] = false;
  }
};

int main(void) {
  std::vector<std::vector<char>> board = {
    {'o', 'a', 'a', 'n'},
    {'e', 't', 'a', 'e'},
    {'i', 'h', 'k', 'r'},
    {'i', 'f', 'l', 'v'}
  };

  std::vector<std::string> words = {
    "oath",
    "pea",
    "eat",
    "rain"
  };

  std::vector<std::string> found = Solution().findWords(board, words);
  for(std::string word: found) {
    std::cout << word << std::endl;
  }

  return 0;
}
