#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *links[256];
};
class spellchecker
{
    private:
        node *getcommonprefix(node *Node, string word, string &commonprefix);
        node *util(node *Node, string word, string &commonprefix, int ind);
        void collect(node *Node, string commonprefix, deque<string> &sugg);
       
    public:
        node *insert(node *Node, string word, int val, int ind);
        node *findkey(node *Node, string word, int ind);
        void suggestions(node *root, string word);
};
#endif