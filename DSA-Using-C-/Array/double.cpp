#include <iostream>
using namespace std;

int main() {
  
  int arr[5] = {1,2,3,4,5};
  cout << "Given numbers : ";
    for(int index = 0; index <= 4 ; index ++){
    cout << arr[index] << " ";
  }
  cout << endl;
    cout << "double of given numbers : ";
    for(int index = 0; index <= 4 ; index ++){
    cout << arr[index] * 2 << " ";
  }
}