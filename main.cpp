#include <iostream>
#include <string>
#include <string.h>
#include "Sorting.h"

using namespace std;

int main (int argc, char** argv) {
  srand(0);
  Sorting *s = new Sorting();
  int userNum;
  string userFile;
  if (strcmp(argv[1], "create") == 0) {
    try {
      userNum = stoi(argv[2]);
      userFile = argv[3];
      s->GenerateFile(userNum, userFile);
    }

    catch (exception e)
    {
      cout << "Incorrect file format" << endl;
    }
  }
  else if (strcmp(argv[1], "sort") == 0) {
    userFile = argv[2];
    s->ReadFromFile(userFile);
  }
  
  delete s;
  return 0;
}
