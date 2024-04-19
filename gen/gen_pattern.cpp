#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    char remap[26];
    for (int i=0;i<26;++i) remap[i] = 'a' + i;
    shuffle(remap, remap+26);

    int slen = atoi(argv[1]), tlen = atoi(argv[2]);
    string pata(argv[3]), patb(argv[4]);
    for (auto &c:pata) c = remap[c - 'a'];
    for (auto &c:patb) c = remap[c - 'a'];
    while (slen){
        cout << pata.substr(0, min(slen, (int)pata.size()));
        slen -= min(slen, (int)pata.size());
    }
    cout << '\n';
    while (tlen){
        cout << patb.substr(0, min(tlen, (int)patb.size()));
        tlen -= min(tlen, (int)patb.size());
    }
    cout << '\n';
}