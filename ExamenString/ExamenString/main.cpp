//
//  main.cpp
//  ExamenString
//
//  Created by Enrique Barragán on 2/11/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    map<char, int> mymap;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (mymap.find(s[i]) != mymap.end()) {
            mymap[s[i]]++;
        } else {
            mymap[s[i]] = 1;
        }
    }
    map<char, int>::iterator it;
    
    for (it = mymap.begin(); it != mymap.end(); ++it) {
        cout << it->first << " - " << it->second << endl;
    }

    return 0;
}
