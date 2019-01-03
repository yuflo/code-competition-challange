#include "stdio.h"

#define true (char)1
#define false (char)0

typedef char bool;

int n = 4;
int a[] = {1, 2, 4, 7};
int k = 13;

bool dfs(int i, int sum){
  if(i == n) return sum == k;

  if(dfs(i+1, sum)) return true;

  if(dfs(i+1, sum+a[i])) return true;

  return false;
}

bool dfsStack(){

}

int main(int argc, char *argv[]){
  if(dfs(0, 0)) printf("yes\n");
  else printf("no\n");
}
