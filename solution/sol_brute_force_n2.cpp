#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define maxn (int)5e6+50

int match_count[maxn], likelihood[maxn];
char s[maxn], t[maxn];
int min(int a, int b){return a < b ? a : b;}

int main(){
    // scanf("%s%s", s, t);
    ios_base::sync_with_stdio(false); cin.tie(0); cin >> s >> t;
    const int n = strlen(s), m = strlen(t);
    for (int i=0;i<n;++i){
        for (int j=0;j<min(m, n-i);++j){
            if (s[i+j] != t[j]){
                
                break;
            }
            else{
                ++match_count[j];
            }
        }
    }
    for (int i=0;i<min(m, n);++i){
        for (int j=i+1;j<min(m, n);++j){
            if (t[j-i-1] != t[j]){
                break;
            }
            else{
                ++likelihood[j];
            }
        }
    }
    // for (int i=0;i<m;++i) printf("%lld\n", match_count[i] * (likelihood[i] + 1ll));
    for (int i=0;i<m;++i) cout << match_count[i] * (likelihood[i] + 1ll) << '\n';
}