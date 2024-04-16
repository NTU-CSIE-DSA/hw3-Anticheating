#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    int slen = atoi(argv[1]), tlen = atoi(argv[2]);
    cout << jngen::StringRandom::random(slen) << '\n' << jngen::StringRandom::random(tlen) << '\n';
}