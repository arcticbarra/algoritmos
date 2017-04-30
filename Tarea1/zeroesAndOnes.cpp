// Enrique Barragan
// A01370878

#include <iostream>

using namespace std;

int minLength(int n, string s) {
  int index = 0;
  while (index < s.length()) {
    if ((s[index] == '0' && s[index+1] == '1') || (s[index] == '1' && s[index+1] == '0')) {
        s = s.substr(0,index) + s.substr(index+2,s.length()-index-2);
        index = 0;
    } else {
      index++;
    }
  }
  return s.length();
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << minLength(n,s) << endl;
}
