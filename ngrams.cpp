/*
 * Scan a file and try to parse out any JPEGs.
 */
#include "ngrams.h"

using namespace std;

/*
 * Check if a deque is a member of a Table.
 */
bool is_member_table(Table &t, deque<string> k) {
    return (t.find(k) != t.end());
}


/*
 * Check if a string is a member of a Counter.
 */
bool is_member_counter(Counter &t, string k) {
    return (t.find(k) != t.end());
}


/*
 * Give a list of words and a number specifying the length
 * of n-grams to make, make frequency distributions of words that follow
 * a given n-gram for all n-grams in the given words.
 */
Table make_ngrams(int n, char *filename) {
    ifstream in(filename);
    Table counters;

    // We use a deque to represent our ngrams
    deque<string> ngram;


    // Iterate through the words, updating the current n-gram
    // and the frequency distribution for the n-gram
    string word;
    while (in) {
        in >> word;

        // Update frequency distribution
        if (is_member_table(counters, ngram)) {
            if (is_member_counter(counters[ngram], word)) {
                counters[ngram][word] += 1;
            } else {
                counters[ngram][word] = 1;
            }
        } else {
            Counter new_counter;
            new_counter[word] = 1;
            counters[ngram] = new_counter;
        }

        // Update n-gram
        // Ensure ngram is always size n
        if (ngram.size() == n) {
            ngram.pop_front();
        }
        ngram.push_back(word);
    }

    return counters;
}
