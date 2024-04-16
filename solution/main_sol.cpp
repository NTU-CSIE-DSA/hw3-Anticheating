#include <stdio.h>
#include <string.h>
#define maxn (int)5e6+100

char s[maxn], t[maxn];
int kmp[maxn], kmp_depth[maxn], match_cnt[maxn];
void moveRight1(char s[], int l){
    s[l+1] = 0;
    for (int i=l;i>0;--i) s[i] = s[i-1];
}
int main(){
    scanf("%s%s", s, t);
    int m = strlen(s), l = strlen(t);
    // moveRight1(s, m);
    // moveRight1(t, l);
    kmp_depth[0] = 1;
    // kmp[0] = -1;
    for (int i=1, j=0;i<l;++i){
        while (j && t[i] != t[j]) j = kmp[j-1];
        if (t[i] == t[j]) ++j;
        kmp[i] = j;
        if (j) kmp_depth[i] = kmp_depth[j-1]+1;
        else kmp_depth[i] = 1;
    }
    for (int i=0, j=0;i<m;++i){
        while (j && s[i] != t[j]) j = kmp[j-1];
        if (s[i] == t[j]) ++j;
        ++match_cnt[j];
        if (j == l) j = kmp[j-1];
    }
    for (int i=l;i;--i){
        match_cnt[kmp[i-1]] += match_cnt[i];
    }
    for (int i=1;i<=l;++i) printf("%lld\n", (long long)match_cnt[i] * kmp_depth[i-1]);
}