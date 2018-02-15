#include <bits/stdc++.h>
#include <fstream>
#include "spellchecker.h"

using namespace std;

node *spellchecker::findkey(node *Node, string word, int ind)
{
    if(Node == NULL) return Node;

    if(ind == word.length()) return Node;

    return findkey(Node->links[word[ind]], word, ind+1);
}
node *spellchecker::insert(node *Node, string word, int val, int ind)
{
    if(Node == NULL)
    {
        Node = new node();
    }

    if(ind == word.length())
    {
        Node->val = 1;
        return Node;
    }
    char ch = word[ind];
    Node->links[ch] = insert(Node->links[ch], word, val, ind+1);

    return Node;
}
node *spellchecker::util(node *Node, string word, string &commonprefix, int ind)
{
    if(Node->links[word[ind]] == NULL)
        return Node;
    if(ind == word.length())
        return Node;
    commonprefix+=word[ind];
    return util(Node->links[word[ind]], word, commonprefix, ind+1);


}
node *spellchecker::getcommonprefix(node *Node, string word, string &commonprefix)
{
    return util(Node, word, commonprefix, 0);
}
void spellchecker::collect(node *Node, string commonprefix, deque<string> &sugg)
{
    if(Node == NULL)
    {
        return;
    }
    if(Node->val == 1)
    {
        sugg.push_back(commonprefix);
    }
    for(int i = 0; i < 256; ++i)
    {
            collect(Node->links[i], commonprefix+(char) i, sugg);
    }

}
void spellchecker::suggestions(node *root, string word)
{
    string commonprefix = "";
    node *Node = getcommonprefix(root, word, commonprefix);
    deque<string> sugg;
    collect(Node, commonprefix, sugg);
    while(!sugg.empty())
    {
        string temp = sugg.front();
        cout << temp << endl;
        sugg.pop_front();
    }

}