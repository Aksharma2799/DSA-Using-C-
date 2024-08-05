#include <iostream>
using namespace std;
//Half pyramid
/*

*
**
***
****

*/
int main() {

  int n = 5;
  for(int row = 0; row < n; row++){
    for(int col = 0; col < row+1; col++){
      cout << "* ";
    }
    cout << endl;
  }

}