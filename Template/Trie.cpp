#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  unordered_map<char, TrieNode *> children;
  bool isEndOfWord;

  TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(const string &word)
  {
    TrieNode *current = root;
    for (char ch : word)
    {
      if (current->children.find(ch) == current->children.end())
      {
        current->children[ch] = new TrieNode();
      }
      current = current->children[ch];
    }
    current->isEndOfWord = true;
  }

  bool search(const string &word)
  {
    TrieNode *node = searchNode(word);
    return (node != nullptr && node->isEndOfWord);
  }

  bool startsWith(const string &prefix)
  {
    return (searchNode(prefix) != nullptr);
  }

private:
  TrieNode *searchNode(const string &word)
  {
    TrieNode *current = root;
    for (char ch : word)
    {
      if (current->children.find(ch) == current->children.end())
      {
        return nullptr;
      }
      current = current->children[ch];
    }
    return current;
  }
};