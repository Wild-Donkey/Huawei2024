#ifndef MY_BOAT
#define MY_BOAT
#include <bits/stdc++.h>

#include "berth.hpp"
using namespace std;

extern Berth berth[berth_num];
extern unsigned Frameid;

struct Boat {
  unsigned num;
  int pos;          //-1 For destination
  unsigned status;  // 0 for moving, 1 for loading or available, 2 for queuing
  unsigned when_to_go;
  void Pick() {
    unsigned Mx(0), Bth(0);
    for (unsigned i(0); i < berth_num; ++i) {
      if (berth[i].when_available <= Frameid + berth[i].transport_time) {
        if (Mx <= berth[i].Sum) Bth = i, Mx = berth[i].Sum;
      }
    }
    berth[Bth].when_available =
        Frameid + berth[Bth].transport_time + berth[Bth].loading_time;
    printf("ship %u %u\n", num, Bth);
  }
};

#endif