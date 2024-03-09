#ifndef MY_BERTH
#define MY_BERTH
#include <bits/stdc++.h>

using namespace std;

extern const int n, N;
extern const int berth_num;

struct Berth {              // Berth to berth 50000 frames.
  unsigned x;               // [x, x + 3]
  unsigned y;               // [y, y + 3]
  unsigned transport_time;  // berth <-> dest
  unsigned loading_speed;   // Obj per frame
  unsigned Obj;             // Number of objects
  Berth() {}
  Berth(unsigned x, unsigned y, unsigned transport_time,
        unsigned loading_speed) {
    this->x = x;
    this->y = y;
    this->transport_time = transport_time;
    this->loading_speed = loading_speed;
  }
};
#endif