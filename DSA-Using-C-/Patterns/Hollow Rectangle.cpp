#include <iostream>
using namespace std;

int main() {
  int rowCount, colCount;
  cin >> rowCount;
  cin >> colCount;

  for(int i = 0; i<rowCount; i++){
    if(i == 0 || i == rowCount-1){
      for(int j = 0; j<colCount; j++ ){
        cout << "* ";
      }
    }
    else{
      cout << "* ";
      for(int k = 0; k<colCount-2; k++){
        cout << "  ";
      }
      cout << "* ";
    }
    cout<<endl;
  }
}