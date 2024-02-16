#include <iostream>

using namespace std;

int main() {
  // Define characters for representing different elements
  const char water = '~';
  const char mountain = '^';
  const char snow = '*';
  const char cloud = '.';

  // Define island size and mountain position
  const int islandWidth = 20;
  const int islandHeight = 10;
  const int mountainX = islandWidth / 2;
  const int mountainY = islandHeight / 2;

  // Print top half of the island (water)
  for (int i = 0; i < islandHeight / 2; i++) {
    for (int j = 0; j < islandWidth; j++) {
      cout << water;
    }
    cout << endl;
  }

  // Print mountain base
  for (int i = 0; i < mountainY; i++) {
    for (int j = 0; j < islandWidth; j++) {
      if (j >= mountainX - i && j <= mountainX + i) {
        cout << mountain;
      } else {
        cout << water;
      }
    }
    cout << endl;
  }

  // Print mountain peak with snow
  for (int i = 0; i < mountainY / 2; i++) {
    for (int j = 0; j < islandWidth; j++) {
      if (j >= mountainX - (mountainY / 2 - i) && j <= mountainX + (mountainY / 2 - i)) {
        cout << snow;
      } else {
        cout << water;
      }
    }
    cout << endl;
  }

  // Print clouds around the peak
  for (int i = 0; i < mountainY / 4; i++) {
    for (int j = 0; j < islandWidth; j++) {
      if (j >= mountainX - (mountainY / 4 + i) && j <= mountainX + (mountainY / 4 + i)) {
        cout << cloud;
      } else {
        cout << water;
      }
    }
    cout << endl;
  }

  // Print bottom half of the island (water)
  for (int i = islandHeight / 2; i < islandHeight; i++) {
    for (int j = 0; j < islandWidth; j++) {
      cout << water;
    }
    cout << endl;
  }

  return 0;
}
