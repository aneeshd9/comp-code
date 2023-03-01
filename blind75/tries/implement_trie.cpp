#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::fill;
using std::string;
using std::vector;

class Trie {
public:
  Trie() {
    graph = vector<Node>();
  }

  void insert(string word) {
    int current = 0;
    for (int i = 0; i < word.size(); ++i) {
      if (current >= graph.size()) {
        graph.push_back(Node());
      }

      int charIndex = charToIndex(word[i]);
      if (graph[current].next[charIndex] == -1) {
        graph[current].next[charIndex] = graph.size();
        current = graph.size();
      } else {
        current = graph[current].next[charIndex];
      }

      if (i == word.size() - 1) {
        graph[current].leaf = true;
      }
    }
  }

  void printTrie() const {
    cout << "Number of node: " << graph.size() << endl;
    for (int i = 0; i < graph.size(); ++i) {
      cout << i << ": ";
      for (int j = 0; j < 26; ++j) {
        if (graph[i].next[j] != -1) {
          cout << indexToChar(j) << ", ";
        }
      }
      cout << endl;
    }
  }

  bool search(string word) {
    if (graph.size() == 0)
      return false;
    
    int current = 0;
    for (int i = 0; i < word.size(); ++i) {
      int charIndex = charToIndex(word[i]);
      if (graph[current].next[charIndex] == -1)
        return false;
      else
        current = graph[current].next[charIndex];
    }

    if (graph[current].leaf) return true;
    else return false;
  }

  bool startsWith(string prefix) {
    if (graph.size() == 0)
      return false;

    int current = 0;
    for (int i = 0; i < prefix.size(); ++i) {
      int charIndex = charToIndex(prefix[i]);
      if (graph[current].next[charIndex] == -1)
        return false;
      else
        current = graph[current].next[charIndex];
    }

    return true;
  }

  static int charToIndex(char ch) {
    return ch - 'a';
  }

  static char indexToChar(int i) {
    return i + 'a';
  }

private:
  class Node {
  public:
    int next[26];
    bool leaf;

    Node() {
      fill(next, next + 26, -1);
      leaf = false;
    }
  };
  
  vector<Node> graph;
};

int main(void) {
  Trie trie;
  trie.insert("apple");
  cout << trie.search("apple") << endl;
  cout << trie.search("app") << endl;
  cout << trie.startsWith("app") << endl;
  trie.insert("app");
  cout << trie.search("app") << endl;

  Trie trie2;
  trie2.insert("a");
  cout << trie2.search("a") << endl;
  cout << trie2.startsWith("a")  << endl;

  return 0;
}
