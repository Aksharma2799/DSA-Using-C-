#include <iostream>
using namespace std;
//Inverted Half Pyramid
/*

****
***
**
*




*/
int main() {

  int n = 5;
  for(int row = 0; row < n; row ++){
    for(int col = 0; col < n - row; col ++){
      cout << "* ";
    }
    cout << endl;
  }

}