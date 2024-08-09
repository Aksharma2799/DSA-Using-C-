#include <iostream>
using namespace std;

// void ReverseNumber(int num){

//   int LastDigit, temp = 0;

//   while(num > 0){

//     LastDigit = num%10;
//     temp = temp*10 + LastDigit;
//     num /= 10;

//   }
//   cout << temp << endl;

// }

void PaliNumber(int num){
  int LastDigit, temp = 0;
  int store = num;

  while(num > 0){ 
    LastDigit = num%10;
    temp = temp*10 + LastDigit;
    num /= 10;
  }
  if(temp == store){
    cout << "PaliNumber" << endl;
  }
    else{
    cout << "not a palindrome number" << endl;
  }
}
int main() {
  int num = 12321;
  // ReverseNumber(num);
  PaliNumber(num);
}