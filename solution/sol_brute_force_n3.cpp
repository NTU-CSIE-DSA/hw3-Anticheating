#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn (int)5e6+10

char s[maxn], t[maxn];
int match_cnt[maxn], likelihood[maxn];
int main(){
    scanf("%s%s", s, t);
    const int n = strlen(s), m = strlen(t);

    for (int l=0;l<m;++l){
        for (int i=0;i+l<n;++i){}
    }
}