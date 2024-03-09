#ifndef MY_BOAT
#define MY_BOAT
#include <bits/stdc++.h>
using namespace std;

struct Boat {
  unsigned num;
  int pos;          //-1 For destination
  unsigned status;  // 0 for moving, 1 for loading or available, 2 for queuing
};

#endif