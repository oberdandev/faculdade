#include <iostream>
#include <stdio.h>
#include <variant>
#include <string.h>
#include <locale.h>
#include <algorithm>

using namespace std;

int main (){
  string buf;

  cout << "Enter a text" << endl;
  cin >> buf;
  

  cout << "Texto maisculo" << buf << endl;

  return 0;
}