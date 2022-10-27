.PHONY: all clean

CFLAGS ?= -g -O2 -Wall -fPIC -shared -std=c++11

LUA_PATH ?= ./lua-5.4.2
INCLUDE_PATH ?= -I$(LUA_PATH)

all: trie.so

%.o:%.cpp
	g++ $(CFLAGS) $(INCLUDE_PATH) -o $@ -c $^

trie.so:lTrieFilter.o TrieFilter.o
	g++ $(CFLAGS) $(INCLUDE_PATH) $^ -o $@

clean:
	-rm -rf *.o *.so