local trie = require "trie"
local trie_obj = trie.new("test")

print("~~~",trie_obj:check("测试敏感字"))
print("~~~",trie_obj:check("测试敏感字中"))