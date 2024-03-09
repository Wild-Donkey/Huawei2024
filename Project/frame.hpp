#ifndef MY_INPUT
#define MY_INPUT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern Robot robot[robot_num + 10];
extern Boat boat[10];
Command CmdList[105];
unsigned CntCmd;

int Input() {
  scanf("%u%u", &Frameid, &money);
  unsigned ObjNum;
  scanf("%u", &ObjNum);
  for (int i = 1; i <= ObjNum; i++) {
    int x, y, val;
    scanf("%d%d%d", &x, &y, &val);
  }
  for (int i = 0; i < robot_num; i++) {
    int sts;
    scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);
  }
  for (int i = 0; i < 5; i++) scanf("%d%d\n", &boat[i].status, &boat[i].pos);
  char okk[100];
  scanf("%s", okk);
  return Frameid;
}
void Play() {
  CntCmd = 0;
  for (unsigned i = 1; i <= CntCmd; ++i) CmdList[i].Prt();
  puts("OK");
  fflush(stdout);
}
#endif
