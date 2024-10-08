#ifndef MY_INPUT
#define MY_INPUT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern unsigned GoodValSum, GoodSum, ValAvr;
extern Robot robot[robot_num];
extern Boat boat[10];
extern queue<Object> Objects;
Command CmdList[105];
unsigned CntCmd;
extern short RobotFrame[Size + 10][Size + 10];

void Input() {
  scanf("%u%u", &Frameid, &money);
  unsigned ObjNum;
  scanf("%u", &ObjNum);
  for (int i = 1; i <= ObjNum; i++) {
    unsigned ox, oy, val;
    scanf("%u%u%u", &ox, &oy, &val);
    GoodValSum += (gds[ox + 1][oy + 1] = val);
    Objects.push((Object){Frameid + 1000, ox + 1, oy + 1});
  }
  GoodSum += ObjNum, ValAvr = GoodValSum / (GoodSum + 1);
  while (Objects.size() && Objects.front().DisappearFrame <= Frameid) {
    gds[Objects.front().x][Objects.front().y] = 0;
    Objects.pop();
  }
  for (unsigned i = 0; i < robot_num; i++) {
    unsigned Recover, State;
    scanf("%u%u%u%u", &State, &robot[i].x, &robot[i].y, &Recover);
    robot[i].status = State, ++(robot[i].x), ++(robot[i].y);
    RobotFrame[robot[i].x][robot[i].y] = Frameid;
  }
  for (int i = 0; i < 5; i++) scanf("%d%d\n", &boat[i].status, &boat[i].pos);
  char okk[100];
  scanf("%s", okk);
}
void Play() {
  Input();
  CntCmd = 0;
  for (unsigned i(0); i < 5; ++i)
    if (boat[i].status == 1) {
      if (boat[i].pos == -1)
        boat[i].Pick();
      else if (Frameid >= boat[i].when_to_go) {
        berth[boat[i].pos].Udt();
        // fprintf(stderr, "Frame %u Boat %u Go %u\n", Frameid, i, boat[i].pos);
        printf("go %u\n", i);
        break;
      }
    }
  for (unsigned i(0); i < robot_num; ++i)
    if (!robot[i].status) robot[i].Go(robot[i].SearchGood());
  // fprintf(stderr, "Here Frame %u\n", Frameid);
  // fprintf(stderr, "Done\n");
  for (unsigned i(0); i < robot_num; ++i)
    if (robot[i].status) {
      robot[i].Go(robot[i].SearchBerth());
      if (robot[i].InBerth())
        robot[i].Drop(), robot[i].Go(robot[i].SearchGood());
    }
  for (unsigned i(1); i <= CntCmd; ++i) CmdList[i].Prt();
  puts("OK");
  fflush(stdout);
}
#endif
