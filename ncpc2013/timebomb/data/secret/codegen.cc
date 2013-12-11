#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

char matrix[5][401];

void put_digit(int pos, int digit) {
  char mask[15];

  switch(digit) {
    case 0:
      mask = {'*','*','*',
              '*',' ','*',
              '*',' ','*',
              '*',' ','*',
              '*','*','*'};
      break;
    case 1:
      mask = {' ',' ','*',
              ' ',' ','*',
              ' ',' ','*',
              ' ',' ','*',
              ' ',' ','*'};
      break;
    case 2:
      mask = {'*','*','*',
              ' ',' ','*',
              '*','*','*',
              '*',' ',' ',
              '*','*','*'};
      break;
    case 3:
      mask = {'*','*','*',
              ' ',' ','*',
              '*','*','*',
              ' ',' ','*',
              '*','*','*'};
      break;
    case 4:
      mask = {'*',' ','*',
              '*',' ','*',
              '*','*','*',
              ' ',' ','*',
              ' ',' ','*'};
      break;
    case 5:
      mask = {'*','*','*',
              '*',' ',' ',
              '*','*','*',
              ' ',' ','*',
              '*','*','*'};
      break;
    case 6:
      mask = {'*','*','*',
              '*',' ',' ',
              '*','*','*',
              '*',' ','*',
              '*','*','*'};
      break;
    case 7:
      mask = {'*','*','*',
              ' ',' ','*',
              ' ',' ','*',
              ' ',' ','*',
              ' ',' ','*'};
      break;
    case 8:
      mask = {'*','*','*',
              '*',' ','*',
              '*','*','*',
              '*',' ','*',
              '*','*','*'};
      break;
    case 9:
      mask = {'*','*','*',
              '*',' ','*',
              '*','*','*',
              ' ',' ','*',
              '*','*','*'};
      break;
  }

  char *ptr = &mask[0];
  FOR(i,0,5) {
    FOR(j,pos*4,pos*4+3) {
      matrix[i][j] = *ptr;
      ptr++;
    }
    matrix[i][pos*4+3] = ' ';
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " [number of digits (between 2 and 8 or zero for random)] [corruption probability]" << endl;
    exit(1);
  } 

  srand(time(NULL));

  int numberOfDigits = atoi(argv[1]);
  double corrProbability = atof(argv[2]);

  if (numberOfDigits == 0) {
    numberOfDigits = rand() % 7 + 2;
  }

  if ((numberOfDigits < 2) || (numberOfDigits > 8)) {
    cerr << "Number of digits must be between 2 and 8" << endl;
    exit(1);
  }

  if ((corrProbability < 0.0) || (corrProbability > 1.0)) {
    cerr << "Corruption probability must be between 0 and 1" << endl;
    exit(1);
  }

  FOR(i,0,numberOfDigits) {
    put_digit(i, rand() % 10);
  }  

  if (double(rand() % 101) / 100.0 < corrProbability) {
    //Note that a digit corruption might actually produce another valid digit
    int numberOfCorruptions = rand() % 5 + 1;
    
    FOR(i,0,numberOfCorruptions) {
      int posToCorrupt = rand() % numberOfDigits;
      int rowToCorrupt = rand() % 5;
      int colToCorrupt = 4*posToCorrupt + (rand() % 3);
      if (matrix[rowToCorrupt][colToCorrupt] == ' ') 
        matrix[rowToCorrupt][colToCorrupt] = '*';
      else
        matrix[rowToCorrupt][colToCorrupt] = ' ';
    }
  }

  FOR(i,0,5) {
    FOR(j,0,numberOfDigits*4-1) {
      cout << matrix[i][j];
    }
    cout << '\n';
  }

  return 0;
}
