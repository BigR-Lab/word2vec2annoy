#include "../w2v-to-annoy.h"
#include "../load-from-annoy-by-word.h"
#include <string>
#include <vector>

char testBinPath[] = "data/text8-vector.bin";
char testIndexPath[] = "test-index.txt";
char testAnnoyPath[] = "test-annoy.tree";

char testWord[] = "platypus";

int main(int argc, char **argv) {
  long long dimensions;
  w2vToAnnoy(testBinPath, testIndexPath, testAnnoyPath, &dimensions);

  float loadedVector[dimensions];

  if (loadFromAnnoyByWord(testIndexPath, testAnnoyPath, testWord, 
    dimensions, loadedVector)) {

    for (int i = 0; i < 40; ++i) {
      printf("%f, ", loadedVector[i]);
    }
  }
  else {
    printf("Could not load vector!\n");
  }
}
