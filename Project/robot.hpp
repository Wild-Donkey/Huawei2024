#ifndef MY_ROBOT
#define MY_ROBOT
#include <bits/stdc++.h>

using namespace std;

struct Robot {
  int x, y, goods;
  int status;
  int mbx, mby;
  Robot() {}
  Robot(int startX, int startY) {
    x = startX;
    y = startY;
  }
};
#endif
