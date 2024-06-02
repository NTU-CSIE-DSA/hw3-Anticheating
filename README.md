# DSA 2024 Homework 3 Programming Problem 2 (Anticheating)

## Tutorial

For counting the number of valid shifts, build the $\pi$ function for string $c$ first. Denote $\pi^2(n) = \pi(\pi(n))$, $\pi^3(n) = \pi(\pi(\pi(n)))$, and so on.

Then, use the KMP algorithm to determine how many occurrences of $c$ are in $s$. However, instead of looking for complete matches, record the length of the prefix of $c$ that has matched successfully at each step. This way, all $\pi^i(n)$ also match successfully, allowing us to count matches using this method. That is, if there is a valid shift with substring length $\ell$, then there is also a valid shift with substring length $\pi^k(\ell)$.

For calculating the likelihood of prefix $i$, it is simply the minimum $j + 1$ where $\pi^j(i) = 0$. We can denote this value as the depth of KMP, that is,
$$\texttt{kmp\\_depth[i]} = \texttt{kmp\\_depth[\text{$\pi$}(i)]} + 1$$

## Sample Code 
```c
#include <stdio.h>
#include <string.h>
#define MAXN (int) 5e6+10

// The input string
char S[MAXN], C[MAXN];

// kmp[] is the ordinary pi array for KMP on C
// kmp_depth[] is the "depth" of KMP
// match_cnt[] is the count of matches of each prefix
int kmp[MAXN], kmp_depth[MAXN], match_cnt[MAXN];

int main(){
    scanf("%s%s", S, C);
    int m = strlen(S), l = strlen(C);

    // pi[0] = 0 so by definition, the KMP depth of 0 is 1
    kmp_depth[0] = 1;

    // Build an ordinary pi array
    for (int i = 1, j = 0; i < l; ++i) {
        while (j && C[i] != C[j]) j = kmp[j - 1];
        if (C[i] == C[j]) ++j;
        kmp[i] = j;

        // Record the KMP depth
        if (j) kmp_depth[i] = kmp_depth[j - 1] + 1;
        else kmp_depth[i] = 1;
    }

    // Similar to the usual string matching, match how many C are in S
    for (int i = 0, j = 0; i < m; ++i) {
        while (j && S[i] != C[j]) j = kmp[j - 1];
        if (S[i] == C[j]) ++j;
        ++match_cnt[j]; // Record which prefix of C is matched.

        // When a match is found, do not return immediately. Instead, continue matching
        if (j == l) j = kmp[j - 1];
    }

    for (int i = l; i > 0; --i) {
        // Update the match count
        match_cnt[kmp[i - 1]] += match_cnt[i];
    }

    for (int i = 1; i <= l; ++i) {
        printf("%lld\n", (long long) match_cnt[i] * kmp_depth[i - 1]);
    }
}
```

## Common Mistakes
1. Mixing 0-based and 1-based indexing when using KMP.
2. Not setting the array size larger than $5\times 10^6$, which means `'\0'` will not be scanned.
3. If the strings $S$ and $C$ consist of $5\times 10^6$ `A`s, the largest number in the output is about $\left(\frac{5\times 10^6}{2}\right)^2$, so not using `long long` will result in a Wrong Answer.

## Coding Tips
1. Instead of directly adding $\texttt{match\\_cnt[i]}$ to $\texttt{match\\_cnt[\text{\(\pi^k\)}(i)]}$ for all $1\leq k\leq \texttt{kmp\\_depth[i]}$, we can just add $\texttt{match\\_cnt[i]}$ to $\texttt{match\\_cnt[\text{\(\pi\)}(i)]}$ for each $i$.
