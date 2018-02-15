#include <bits/stdc++.h>
#include <fstream>
#include "spellchecker.h"

using namespace std;

int main()
{
    ifstream in("words.txt");

    spellchecker obj;
    node *root = NULL;
    string word;

    while(in)
    {
        in >> word;
        root = obj.insert(root, word, 1, 0);
    }
    string searchkey;
    cout << "Enter the word to search: ";
    cin >> searchkey;

    node *temp = obj.findkey(root, searchkey, 0);
    if(temp != NULL and temp->val == 1)
    {
        cout << "It is here\n";
    }
    else
    {
        cout << "Wrong word\n";
        cout << "Possible suggestions are(is)\n";
        obj.suggestions(root, searchkey);
    }

    return 0;
}