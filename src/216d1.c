/*
 * Copyright: C.lee@eigenlab.com TODO
 */

#include "stdio.h"

#define true (char)1
#define false (char)0

typedef char bool;

void permute_pos(int pos, int n, int perm[], bool used[]){
  if(pos == n) return;
  for(int i = 0; i < n; i++){
    if(!used[i]){
      perm[pos] = i;
      used[i] = true;
      permute_pos(pos+1, n, perm, used);
      used[i] = false;
    }
  }
  return;
}

void do_permute(int n, int perm[], bool used[]){
  permute_pos(2, n, perm, used);
}

int main(int argc, char* argv[]){

  int n = 5;
  int test[] = {1, 2, 3, 4, 5}; //c99
  bool used[n];

  // init-used
  for(int i=0; i < n; i++) used[i] = false;
  do_permute(n, test, used);
  for(int i=0; i < n; i++) printf("%d,", test[i]);

}
