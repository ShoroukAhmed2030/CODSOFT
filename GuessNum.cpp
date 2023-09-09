#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main() {
  int Guess_num, Real_num, NoTry=0 ;

  cout << "please enter your guessing number between [0:100]";
  cin >> Guess_num;
  srand(time(0));
  Real_num = rand() % 101; // 0 + (100 - 0 + 1)

  while(true){
     NoTry++;
   if (Real_num==Guess_num){
   cout<<"correct :) ,Your Guessing number is correct"<<"\n"<<"The number of trials is :"<<NoTry;
   break;
    } else if (Guess_num > Real_num) {
    cout << "wrong!, Your guessing number is greater than number"<<endl;
    } else  
    cout << "wrong!, Your guessing number is less than number"<<endl;
  cin >> Guess_num;
 } 
  return 0;
}