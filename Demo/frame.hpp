#ifndef MY_INPUT
#define MY_INPUT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
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
    gds[ox + 1][oy + 1] = val;
    Objects.push((Object){Frameid + 1000, ox + 1, oy + 1});
  }
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
  // fprintf(stderr, "Here Frame %u\n", Frameid);
  CntCmd = 0;
  for (unsigned i(0); i < 5; ++i)
    if (boat[i].status == 1) {
      if (boat[i].pos == -1)
        boat[i].Pick();
      else if (Frameid >= boat[i].when_to_go) {
        berth[boat[i].pos].Udt();
        fprintf(stderr, "Boat %u Go %u At %u With %u\n", i, boat[i].pos,
                Frameid);
        printf("go %u\n", i);
        break;
      }
    }
  for (unsigned i(0); i < robot_num; ++i) {
    if (robot[i].status) {
      robot[i].Go(robot[i].SearchBerth());
      if (robot[i].InBerth())
        robot[i].Drop(), robot[i].Go(robot[i].SearchGood());
    } else {
      robot[i].Go(robot[i].SearchGood());
      continue;
    }
  }
  for (unsigned i(1); i <= CntCmd; ++i) CmdList[i].Prt();
  puts("OK");
  fflush(stdout);
}
#endif
