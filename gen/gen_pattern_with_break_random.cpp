#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    char remap[26];
    for (int i=0;i<26;++i) remap[i] = 'a' + i;
    shuffle(remap, remap+26);

    int slen = atoi(argv[1]), tlen = atoi(argv[2]);
    int patlen = atoi(argv[3]);
    int patchar = atoi(argv[4]);
    int mode = atoi(argv[5]);
    double break_rate = rnd.nextf();
    string pata, patb;
    for(int i = 0; i < patlen; i++) {
      char c1 = remap[rnd.next(patchar)];
      char c2 = remap[rnd.next(patchar)];
      if(mode == 1 || rnd.nextf() < 0.5) {
        c2 = c1;
      }
      pata += c1;
      patb += c2;
    }
    while (slen){
        if (rnd.nextf() < break_rate){
            --slen;
            cout << (char)('a' + rnd.next(26));
            continue;
        }
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
