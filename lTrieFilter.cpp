#include "TrieFilter.h"

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <stdlib.h>
    #include <stdio.h>

    int luaopen_trie(struct lua_State *L);
}

#define check_trie(L) (Trie **)luaL_checkudata(L, 1, "Trie")

static int lnew(lua_State* L){
    size_t l;
    std::string filePath = luaL_checklstring(L, 1, &l);

    Trie **trie = (Trie **) lua_newuserdata(L, sizeof(Trie *));
    *trie = new Trie();
    (*trie)->load_from_file(filePath);

    luaL_getmetatable(L, "Trie");
    lua_setmetatable(L, -2);
    return 1;
}

static int lcheck_str(lua_State* L){
    Trie **trie = check_trie(L);

    size_t l;
    std::string str = luaL_checklstring(L, 2, &l);
    
    bool ret = (*trie)->check_str(str);

    lua_pushboolean(L, ret);
    return 1;
}

//require trie
LUAMOD_API int luaopen_trie(struct lua_State *L) {
    luaL_checkversion(L);

    if (!luaL_newmetatable(L, "Trie")) {
        luaL_error(L, "关联元表失败\n");
    }
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");

     luaL_Reg func[] = {
        {"check", lcheck_str },
        {NULL,NULL}
    };
    luaL_setfuncs(L, func, 0);

    luaL_Reg lib[] = {
        {"new",  lnew},
        {NULL,NULL}
    };

    luaL_newlib(L, lib);
    return 1;
}