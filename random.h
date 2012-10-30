#include <cstdlib> // <-- this is the library for randomness

#include <string>
#include <map>

using namespace std;

// Call this function once before generating any random numbers
// Do not call it again!
// It uses your computer's clock to ensure that your program gets fresh
// random numbers.
void init_rand();

// Returns a random number between 0 (inclusive) and limit (exclusive)
int rand_up_to(int min, int max);


/*
 * Choose an item from choices according to the given weights.
 */
std::string choice(map<string, int> choices);
