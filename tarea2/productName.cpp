/*
Enrique Barragan Gonzalez
A01370878
Algoritmos

Changing the product name
 */

#include <iostream>

using namespace std;

string changeLetters(string s, char a, char b) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == a) {
      s[i] = b;
    } else if (s[i] == b) {
      s[i] = a;
    }
  }
  return s;
}

int main() {

  int n = 0;
  string name;
  char a,b;
  cin >> n >> name;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    name = changeLetters(name, a, b);
  }

  cout<<name<<endl;
  return 0;
}
