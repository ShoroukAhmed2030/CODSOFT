#include<iostream>
using namespace std;

double num1, num2, ans;
char opr;  int flage ;

double sum(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);

int main() {

  while (true) {

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> opr;
    flage=0;
    
    switch (opr) {
      case '+':
        ans = sum(num1, num2); break;
      case '-':
        ans = sub(num1, num2); break;
      case '*':
      case 'x':
      case 'X':
        ans = mul(num1, num2); break;
      case '/':
        if (num2 == 0) {
          cout << "ERROR: Can't divide by zero."<<endl ;
          flage=1;
        } else {
          ans = div(num1, num2); 
        } break;
      default:
        cout << "Wrong operation."<<endl ;
        flage=1; break;;
    }
    if(flage==0)
    cout << num1 << opr << num2 << " = " << ans<<endl;
  } 
  return 0;
}

double sum(double num1, double num2) {
  return num1 + num2; }

double sub(double num1, double num2) {
  return num1 - num2; }

double mul(double num1, double num2) {
  return num1 * num2; }

double div(double num1, double num2) {
  return num1 / num2; }
