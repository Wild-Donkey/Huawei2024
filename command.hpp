#ifndef MY_COMMAND
#define MY_COMMAND
#include <bits/stdc++.h>
using namespace std;

struct Command {
  unsigned Type;  // 0: Move, 1: Get, 2: Pull, 3: Ship, 4: Go
  int Arg1, Arg2;
  inline void Prt() {
    switch (Type) {
      case 0:
        printf("move %d %d\n", Arg1, Arg2);
        break;
      case 1:
        printf("get %d\n", Arg1);
        break;
      case 2:
        printf("pull %d\n", Arg1);
        break;
      case 3:
        printf("ship %d %d\n", Arg1, Arg2);
        break;
      case 4:
        printf("go %d\n", Arg1);
        break;
    }
  }
};
#endif