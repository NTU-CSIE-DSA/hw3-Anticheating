#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    char remap[26];
    for (int i=0;i<26;++i) remap[i] = 'a' + i;
    shuffle(remap, remap+26);

    int slen = atoi(argv[1]), tlen = atoi(argv[2]);
    int pattern_length = atoi(argv[3]);
    double break_rate = atof(argv[4]);
    string pat(pattern_length, 'a');
    for (int i=0;i<pattern_length;++i) pat[i] = rnd.next((int)'a', (int)'z'+1);

    for (auto &c:pat) c = remap[c - 'a'];
    // for (auto &c:patb) c = remap[c - 'a'];
    while (slen){
        if (rnd.nextf() < break_rate){
            --slen;
            cout << (char)('a' + rnd.next(26));
            continue;
        }
        cout << pat.substr(0, min(slen, (int)pat.size()));
        slen -= min(slen, (int)pat.size());
    }
    cout << '\n';
    while (tlen){
        cout << pat.substr(0, min(tlen, (int)pat.size()));
        tlen -= min(tlen, (int)pat.size());
    }
    cout << '\n';
}