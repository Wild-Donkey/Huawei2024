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
    float Mx(0), Tmp;
    unsigned Bth(0);
    // fprintf(stderr, "Boat %u Pick\n", num);
    for (unsigned i(0); i < berth_num; ++i) {
      if (berth[i].when_available < Frameid + berth[i].transport_time) {
        Tmp = (berth[i].Sum + 1.0) / (berth[i].transport_time + 1.0);
        if (Mx <= Tmp) Bth = i, Mx = Tmp;
      }
    }
    // fprintf(stderr, "Pick %u Val %u Arrive at %u\n", Bth, berth[Bth].Sum,
    // Frameid + berth[Bth].transport_time);
    when_to_go = berth[Bth].when_available =
        Frameid + berth[Bth].transport_time + berth[Bth].loading_time + 1;
    printf("ship %u %u\n", num, Bth);
  }
};

#endif