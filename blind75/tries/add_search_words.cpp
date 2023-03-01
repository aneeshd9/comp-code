#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class WordDictionary {
public:
  WordDictionary() {
    trie = std::vector<Node>();
    trie.push_back(Node());
  }

  void insert(std::string word) {
    int current = 0;

    for (int i = 0; i < word.size(); ++i) {
      int charIndex = word[i] - 'a';
      if (trie[current].next[charIndex] == -1) {
        trie.push_back(Node());
        trie[current].next[charIndex] = trie.size() - 1;
      }
      current = trie[current].next[charIndex];
    }

    trie[current].leaf = true;
  }

  bool search(std::string word) { return search(word, 0, 0); }

  bool search(std::string &word, int trieIndex, int wordIndex) {
    if (trieIndex >= trie.size()) {
      return false;
    } else if (wordIndex >= word.size()) {
      return trie[trieIndex].leaf;
    } else if (word[wordIndex] == '.') {
      for (int nextTrieIndex : trie[trieIndex].next) {
        if (nextTrieIndex != -1 && search(word, nextTrieIndex, wordIndex + 1))
          return true;
      }
      return false;
    } else if (trie[trieIndex].next[word[wordIndex] - 'a'] != -1) {
      return search(word, trie[trieIndex].next[word[wordIndex] - 'a'],
                    wordIndex + 1);
    } else {
      return false;
    }
  }

private:
  class Node {
  public:
    std::vector<int> next;
    bool leaf;

    Node() {
      next = std::vector<int>(26, -1);
      leaf = false;
    }
  };

  std::vector<Node> trie;
};

int main(void) {
  WordDictionary dict;
  dict.insert("add");
  std::cout << dict.search("add") << std::endl;
  std::cout << dict.search(".d.") << std::endl;
  std::cout << dict.search(".d") << std::endl;
  dict.insert("adamant");
  std::cout << dict.search("...man") << std::endl;

  return 0;
}

