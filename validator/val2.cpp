#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    registerValidation();
    string s = inf.readWord();
    ensure(s.size() <= 5000000);
    ensure(s[0] == 'a');
    for (int i=1;i<s.size();++i) ensure(s[i] == s[i-1]);
    inf.readEoln();
    string t = inf.readWord();
    ensure(t.size() <= 5000000);
    ensure(t[0] == s[0]);
    for (int i=1;i<t.size();++i) ensure(t[i] == t[i-1]);
    inf.readEoln();
    inf.readEof();
}