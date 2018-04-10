
/*
#include <cstdio>
#include <climits>

bool gao(long long a, long long b, long long c) {
    if(a >= 0 && b >= 0) {
        if(a > LLONG_MAX - b) return true;
    }
    if(a <= 0 && b <= 0) {
        if(a < LLONG_MIN - b) return false;
    }
    return a + b > c;
}

int main() {
    long long A, B, C;y
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        scanf("%lld %lld %lld", &A, &B, &C);
        printf("Case #%d: %s\n",
                i, (gao(A, B, C) ? "true" : "false") );
    }
    return 0;
}
*/

#include <cstdio>
int main(){
  int T,tcase = 1;
  scanf("%d",&T);
  while(T--){
	  long long a,b,c;
	  scanf("%lld%lld%lld",&a,&b,&c);
	  long long res = a + b;
	  bool flag;
	  if(a > 0 && b > 0 && res <0) flag = true;
	  else if (a < 0 && b < 0 && res >=0) flag = false;
	  else if (res > c) flag = true;
	  else flag = false;
	  if(flag == true) printf("Case #%d: true\n",tcase++);
	  else printf("Case #%d: false\n",tcase++);
  }
  return 0;
}