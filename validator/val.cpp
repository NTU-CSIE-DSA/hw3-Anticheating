#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    registerValidation();
    string s = inf.readWord();
    ensure(s.size() <= 5000000);
    inf.readEoln();
    string t = inf.readWord();
    ensure(t.size() <= 5000000);
    inf.readEoln();
    inf.readEof();
}