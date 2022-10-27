#include "TrieFilter.h"

TrieNode::TrieNode() {
};

TrieNode::~TrieNode() {
    for (auto i : sub_nodes) {
        delete i.second;
    }
    sub_nodes.clear();
}

Trie::Trie() {
    root = new TrieNode(); 
}

Trie::~Trie() {
    delete root;
    root = nullptr;
}

void Trie::load_from_file(const std::string &file_name) {
   
    std::ifstream ifile;
    ifile.open(file_name);

    int count = 0;
    std::string line;
    while (std::getline(ifile, line))
    {
        line = trim(line);
        insert(line);
        count++;
    }
    ifile.close();
    std::cout << "load " << count << " words" << std::endl;
}

void Trie::insert(const std::string &str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t> , char16_t> cvt;
    std::u16string word = cvt.from_bytes(str);

    TrieNode *cur_node = root;
    int len = word.length();

    for (int i = 0; i < len; ++i) {
        char16_t code = word[i];
        TrieNode* sub_node = cur_node->get_sub_node(code);
        if (sub_node == nullptr) {
            sub_node = new TrieNode();
            cur_node->add_sub_node(code, sub_node);
        }
        cur_node = sub_node;
        
        if(i == len -1){
            cur_node->is_end = true;
        }
    }
}

bool Trie::check_str(const std::string &str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t> , char16_t> cvt;
    std::u16string word = cvt.from_bytes(str);

    TrieNode *cur_node = root;
    int len = word.length();

   for (int i = 0; i < len; ++i) {
        char16_t code = word[i];
        TrieNode* sub_node = cur_node->get_sub_node(code);
        if (sub_node == nullptr) {
            return false;
        } else {
            if (i == (len - 1) and sub_node->is_end) {
                return true;
            } else {
                cur_node = sub_node;
            }
        }
    }
    return false;
}