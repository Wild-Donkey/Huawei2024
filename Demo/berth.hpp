#ifndef MY_BERTH
#define MY_BERTH
#include <bits/stdc++.h>

using namespace std;

extern unsigned boat_capacity;

struct Berth {              // Berth to berth 50000 frames.
  unsigned x;               // [x, x + 3]
  unsigned y;               // [y, y + 3]
  unsigned transport_time;  // berth <-> dest
  unsigned loading_speed;   // Obj per frame
  unsigned loading_time;    // empty to full frames
  unsigned when_available;  // frame that available
  unsigned GodNum;          // Numbers of goods;
  unsigned Sum;             // Sum of the pre boat_capacity goods
  queue<unsigned> Obj;      // Goods that can't be loaded at once
  Berth() {}
  Berth(unsigned x, unsigned y, unsigned transport_time,
        unsigned loading_speed) {
    this->x = x;
    this->y = y;
    this->transport_time = transport_time;
    this->loading_speed = loading_speed;
  }
  void Input() {
    scanf("%u%u%u%u", &x, &y, &transport_time, &loading_speed);
    ++x, ++y;
    loading_time = (boat_capacity + (loading_speed - 1)) / loading_speed;
    when_available = 0;
  }
  void Udt() {
    Sum = 0, GodNum = Obj.size();
    for (unsigned i(boat_capacity); i && Obj.size(); --i, Obj.pop())
      Sum += Obj.front();
  }
  void Get(unsigned Val) {
    ++GodNum;
    if (GodNum < boat_capacity) {
      Sum += Val;
      return;
    }
    Obj.push(Val);
  }
};
#endif