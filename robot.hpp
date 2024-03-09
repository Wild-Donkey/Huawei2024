#ifndef MY_ROBOT
#define MY_ROBOT
#include <bits/stdc++.h>

using namespace std;

extern const int n, N;
extern const int robot_num;

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
