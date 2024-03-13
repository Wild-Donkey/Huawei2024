#ifndef MY_INIT
#define MY_INIT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern Berth berth[berth_num];
extern Boat boat[10];
extern char ch[Size + 10][Size + 10];

void Init() {
  for (unsigned i(1); i <= Size; i++) scanf("%s", ch[i] + 1);  // Map [1, n]
  for (unsigned i(0); i < robot_num; i++) robot[i].Num = i;
  for (unsigned i(0); i < 5; i++) boat[i].when_to_go = 0, boat[i].num = i;
  for (unsigned i(0); i < berth_num; i++) {
    unsigned Berid;
    scanf("%u", &Berid);
    berth[Berid].Input();
  }
  scanf("%d", &boat_capacity);  // Same capacity
  char okk[100];
  scanf("%s", okk);
  printf("OK\n");
  fflush(stdout);
}

#endif