#ifndef __TrieFilter_H__
#define __TrieFilter_H__

#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <fstream>
#include <codecvt>
#include <iostream>
#include <locale>
#include <unordered_map>

using namespace std;

class TrieNode 
{
public:
    TrieNode();
    ~TrieNode();

    void add_sub_node(char16_t c, TrieNode *subNode) { sub_nodes[c] = subNode; }
    TrieNode *get_sub_node(char16_t c) { return sub_nodes[c]; }

    bool is_end ;    //关键字结束标识
private:
    std::unordered_map<char16_t, TrieNode*> sub_nodes;
};

class Trie 
{
public:
    Trie();
    ~Trie();

    void load_from_file(const std::string &file_name);
    void insert(const std::string &word);
    bool check_str(const std::string &word);

private:
    TrieNode* root;
};

static inline std::string trim(const std::string& str)
{
	std::string retStr;
	int size = str.size();
	for ( int i = 0; i < size; i++ )
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
		{
			break;
		}
		retStr += str[i];
	}
	return retStr;
}

#endif