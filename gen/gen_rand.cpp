#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    int slen = atoi(argv[1]), tlen = atoi(argv[2]), dict_size = atoi(argv[3]);
    assert(1 <= dict_size && dict_size <= 26);
    int st = rnd.next(27 - dict_size);
    string dict = string(1, 'a' + st) + "-" + string(1, 'a' + st + dict_size - 1);
    cout << jngen::StringRandom::random(slen, dict) << '\n' << jngen::StringRandom::random(tlen, dict) << '\n';
}