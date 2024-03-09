#ifndef MY_INIT
#define MY_INIT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern Berth berth[berth_num + 10];
extern char ch[Size + 10][Size + 10];

void Init() {
  for (int i = 1; i <= Size; i++) scanf("%s", ch[i] + 1);  // Map [1, n]
  for (int i = 0; i < berth_num; i++) {
    int Berid;
    scanf("%d", &Berid);
    scanf("%d%d%d%d", &berth[Berid].x, &berth[Berid].y,
          &berth[Berid].transport_time, &berth[Berid].loading_speed);
  }
  scanf("%d", &boat_capacity);  // Same capacity
  char okk[100];
  scanf("%s", okk);
  printf("OK\n");
  fflush(stdout);
}

#endif