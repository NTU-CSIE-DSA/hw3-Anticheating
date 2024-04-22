#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn (int)5e6+10

char s[maxn], t[maxn];
int main(){
    scanf("%s%s", s, t);
    long long n = strlen(s), m = strlen(t);
    for (int i=1;i<=m;++i) printf("%lld\n", (n - i + 1) * i);
}