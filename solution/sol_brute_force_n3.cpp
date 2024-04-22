#include <stdio.h>
#include <string.h>
#include <stdbool.h>
using namespace std;
#define maxn (int)5e6+10

char s[maxn], t[maxn];
int match_cnt[maxn], likelihood[maxn];
int main(){
    scanf("%s%s", s, t);
    const int n = strlen(s), m = strlen(t);

    for (int l=0;l<m;++l){
        for (int i=0;i+l<n;++i){
            bool ok = true;
            for (int j=0;j<=l;++j){
                if (s[i+j] != t[j]){
                    ok = false;
                    break;
                }
            }
            if (ok) ++match_cnt[l];
        }
    }

    for (int i=0;i<(m < n ? m : n);++i){
        for (int l=0;l<=i;++l){
            bool ok = true;
            for (int j=0;j<=l;++j){
                if (t[j] != t[i-l+j]){
                    ok = false;
                    break;
                }
            }
            if (ok) ++likelihood[i];
        }
    }
    for (int i=0;i<m;++i) printf("%lld\n", (long long) match_cnt[i] * likelihood[i]);
}