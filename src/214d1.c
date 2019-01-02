#include "stdio.h"

typedef char bool;

int main(int argc, char *argv[]){
  int n = 4;
  int a[] = {1, 2, 4, 7};
  int k = 13;

  // solve by `dfs` strategy
  int stk[n]; // c99
  int sp = -1;
  int v = 0;
  int status[n]; // c99

  //for(int i=0; i < n; i++){
  while(true){
    if(status[i] == 2) --sp;
    else if(status[i] == 0){
      if(chain(status, a, sp) > k){
        status[i] = 0;
      }
    }
    else if(status[i] == 1);
  }
}
