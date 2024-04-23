#include <stdio.h>
#include <string.h>

char s[5000001], t[5000001];
int kmp[5000001], pi[5000001], likelihood[5000001], count[5000001] = {};

int main() {
  scanf("%s%s", s, t);
  int len_s = strlen(s), len_t = strlen(t);
  pi[0] = -1;
  likelihood[0] = 1;
  for(int i = 1; i < len_t; i++) {
    int cur = pi[i - 1];
    while(cur != -1 && t[i] != t[cur + 1]) {
      cur = pi[cur];
    }
    if(t[i] == t[cur + 1]) cur++;
    pi[i] = cur;
    if(cur == -1) likelihood[i] = 1;
    else {
      likelihood[i] = likelihood[cur] + 1;
    }
  }
  if(s[0] == t[0]) {
    kmp[0] = 0;
    count[0]++;
  }
  else kmp[0] = -1;
  for(int i = 1; i < len_s; i++) {
    int cur = kmp[i - 1];
    while((cur + 1 == len_t) || (cur != -1 && s[i] != t[cur + 1])) {
      cur = pi[cur];
    }
    if(cur + 1 < len_t && s[i] == t[cur + 1]) cur++;
    kmp[i] = cur;
    if(cur >= 0) count[cur]++;
  }
  for(int i = len_t - 1; i >= 0; i--) {
    if(pi[i] != -1) count[pi[i]] += count[i];
  }
  for(int i = 0; i < len_t; i++) {
    printf("%lld\n", (long long) count[i] * likelihood[i]);
  }
  return 0;
}
