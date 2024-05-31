# DSA 2024 Homework 2 Programming Problem 2 (Dungeons)
# tutorial
For the match counting part, build the $\pi$ function for string $c$ first. Denote $\pi^2(n) = \pi(\pi(n))$, $\pi^3(n) = \pi(\pi(\pi(n))), \dots$ and so on.
Then, use KMP algorithm to match how many occurrence of $c$ is in $s$. However, instead of looking for complete matches, record how long of prefix of $c$ have matched successfully. Then, all $\pi^i(n)$ also matches successfully. We have the count of matches by this method.

For the likelihood of prefix $i$, it is simply the minimum $j + 1$ where $\pi^j(i) = 0$. We cam dempt such value as the depth of KMP.

# sample code 
```c
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
```
