#include <stdio.h>
#include <string.h>
#define maxn (int)5e6+100

// The input string
char S[maxn], C[maxn];

// kmp[] is the ordinary pi array for kmp on C
// kmp_depth[] is the "depth" of kmp
// match_cnt[] is the count of matches of each prefix
int kmp[maxn], kmp_depth[maxn], match_cnt[maxn];
int main(){
    scanf("%s%s", S, C);
    int m = strlen(S), l = strlen(C);

    // pi[0] = 0 so by definition, the kmp depth of 0 is 1
    kmp_depth[0] = 1;
    // Build an ordinary pi array
    for (int i=1, j=0;i<l;++i){
        while (j && C[i] != C[j]) j = kmp[j-1];
        if (C[i] == C[j]) ++j;
        kmp[i] = j;

        // Record the kmp depth
        if (j) kmp_depth[i] = kmp_depth[j-1]+1;
        else kmp_depth[i] = 1;
    }
    // Similar to the usual string matching, match how many C are in S
    for (int i=0, j=0;i<m;++i){
        while (j && S[i] != C[j]) j = kmp[j-1];
        if (S[i] == C[j]) ++j;
        ++match_cnt[j]; // Record which prefix of C is matched.

        // When a match is found, do not return immediately. Instead, look for more by continue matching
        if (j == l) j = kmp[j-1];
    }
    for (int i=l;i;--i){
        // Update the match count.
        match_cnt[kmp[i-1]] += match_cnt[i];
    }
    for (int i=1;i<=l;++i) printf("%lld\n", (long long)match_cnt[i] * kmp_depth[i-1]);
}