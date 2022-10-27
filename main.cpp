#include <iostream>
#include "TrieFilter.h"

int main()
{
    Trie trie;
    trie.load_from_file("test");

    bool ret1 = trie.check_str("测");
    bool ret2 = trie.check_str("测试");
    bool ret3 = trie.check_str("敏感字");
    bool ret4 = trie.check_str("测试敏感字");
    bool ret5 = trie.check_str("测试敏感字中");
    cout<< ret1 << ret2 << ret3 << ret4 << ret5 << endl;
    return 0;
}