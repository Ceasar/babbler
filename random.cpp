#include "random.h"

using namespace std;


// Call this function once before generating any random numbers
// Do not call it again!
// It uses your computer's clock to ensure that your program gets fresh
// random numbers.
void init_rand()
{
  srand(time(NULL));
}

// Returns a random number between 0 (inclusive) and limit (exclusive)
int rand_up_to(int min, int max)
{
  return (rand() % max) + min;
}


/*
 * Choose an item from choices according to the given weights.
 */
std::string choice(map<string,int> choices)
{
    int n;
    int weight1, weight2;
    std::string item1, item2;
    map<string, int>::iterator it;
    
    it = choices.begin();

    item1 = ""; weight1 = 0;
    while (it != choices.end()) {
        item2 = it->first; weight2 = it->second;

        // Choose a random number uniformly from the combined weights of the
        // selected item and the candidate item
        n = rand_up_to(1, weight1 + weight2);

        // If its less than the current weight, select the candidate
        if (n <= weight2) {
            item1 = item2;
        }
        // Increase the weight of the victor by the weight of the candidate
        weight1 = weight1 + weight2;

        it++;
    }
    /*
     * To see why this works, consider choosing from (a, 1), (b, 2) and (c, 3)
     *  -   a will win with (1/3) (against b) * (1/2) (against c) = 1/6 chance
     *  -   b will win with (2/3) (against a) * (1/2) (against c) = 2/6 chance
     *  -   c will win with (1/2) (against a or b) = 3/6 chance
     */
    return item1;

}
