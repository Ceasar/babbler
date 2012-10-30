/*
 * Scan a file and try to parse out any JPEGs.
 */
#include <iostream>
#include <fstream>
#include <utility>
#include <deque>
#include <string>
#include <map>

#include "random.h"

using namespace std;

typedef std::map<string, int> Counter;
typedef std::map<deque<string>, Counter> Table;


bool is_member_table(Table &t, deque<string> k);

bool is_member_counter(Counter &t, string k);

Table make_ngrams(int n, char *filename);
