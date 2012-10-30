#include <iostream>
#include <assert.h>

#include "random.h"
#include "ngrams.h"

using namespace std;


void test_weighted_choice() {
    string got;
    vector<string_int> choices;
    choices.push_back(make_pair("a", 1));
    choices.push_back(make_pair("b", 1));
    for (int i = 0; i < 10; i++) {
        got = choice(choices);
        // cout << "got: " << choice << endl;
        assert(got == "a" || got == "b");
    }
}

void test_is_member_table() {
}

void test_make_ngrams() {
    StringList words;
    words.push_back("hi");
    words.push_back("alice");
    words.push_back("yes");
    words.push_back("hi");
    words.push_back("alice");
    words.push_back("yes");
    words.push_back("hi");
    words.push_back("alice");
    words.push_back("red");
    Table t = make_ngrams(2, words);
    Table::iterator t_it;
    /*
    for ( t_it=t.begin() ; t_it != t.end(); t_it++ ) {
        deque<string> ngram = t_it->first;

        cout << "(";
        for (int i = 0; i < ngram.size(); i++) {
            cout << ngram[i] << ", ";
        }
        cout << ")" << endl;

        Counter c = t_it->second;
        Counter::iterator c_it;
        for ( c_it=c.begin() ; c_it != c.end(); c_it++ ) {
            cout << "    " << c_it->first << " " << c_it->second << endl;
        }
    }
    */
}


int main() {
    init_rand();

    test_weighted_choice();
    test_make_ngrams();

    cout << "OK!" << endl;

    return 0;
}
