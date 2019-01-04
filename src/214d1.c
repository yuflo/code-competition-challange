/*
 * Copyright C.Lee@eigenlab TODO
 */

#include "stdio.h"

#define true (char)1
#define false (char)0

typedef char bool;

int n = 12;
int m = 6;
int a[] = {1,2,3,4,5,6,7,8,9,11,13,17};
int k = 15;

/*
 * recursive solution
 */
bool dfs(int i, int sum){
  if(i == n) return sum == k;

  if(dfs(i+1, sum)) return true;

  if(dfs(i+1, sum+a[i])) return true;

  return false;
}

/*
 * solve by using stack, we make a little extension for the original
 * problem by introducing a constraint (m) to the number of a[i].
 */
bool dfsStack(){

  int stk[n]; // c99
  int status[n]; // c99
  int sp = -1;
  int sum = 0;
  int i = 0;

  status[i] = 1;

  while(i >= 0){

    sum = status[i] == 1 ? sum + a[i] : sum;
    --status[i];

    if(sum == k && (m - sp == status[i]+2)){
      printf("---\n");
      for(int p=0; p <= sp; p++) printf("> %d\n", a[stk[p]]);
      if(status[i] == 0) printf(".> %d\n", a[i]);
      printf("---\n");
      return true;
    }

    else if(sum < k){
      if(status[i] == 0)
        stk[++sp] = i;
      if(i < n - 1)
        status[++i] = 1;
      else{ 
        if(sp >= 0){ i = stk[sp--]; sum -= a[i];}
        else i = -1;
      }
    }

    else{
      if(status[i] == 0) sum -= a[i];
      else{
        if(sp >= 0){ i = stk[sp--]; sum -= a[i];}
        else i = -1;
      }
    }
  }
  return false;
}

int main(int argc, char *argv[]){
  //if(dfs(0, 0)) printf("yes\n");
  //else printf("no\n");
  if(dfsStack()) printf("yes\n");
  else printf("no\n");
}
