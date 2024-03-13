#ifndef MY_INPUT
#define MY_INPUT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern Robot robot[robot_num];
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
    gds[x][y] = val;
  }
  for (unsigned i = 0; i < robot_num; i++) {
    int sts;
    ch[robot[i].x][robot[i].y] = '.';
    scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);
    ch[robot[i].x][robot[i].y] = 'A';
  }
  for (int i = 0; i < 5; i++) scanf("%d%d\n", &boat[i].status, &boat[i].pos);
  char okk[100];
  scanf("%s", okk);
  return Frameid;
}
void Play() {
  CntCmd = 0;
  for (unsigned i(0); i < 5; ++i)
    if (boat[i].status == 1) {
      if (boat[i].pos == -1)
        boat[i].Pick();
      else if (Frameid >= boat[i].when_to_go) {
        berth[boat[i].pos].Udt();
        printf("go %u\n", i);
        break;
      }
    }
  for (unsigned i(0); i < robot_num; ++i) {
    unsigned Tmp(robot[i].SearchGood());
    if (Tmp < 4) robot[i].Go(Tmp);
    continue;
  }
  for (unsigned i = 1; i <= CntCmd; ++i) CmdList[i].Prt();
  puts("OK");
  fflush(stdout);
}
#endif
