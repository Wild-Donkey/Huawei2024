#ifndef MY_INIT
#define MY_INIT
#include <bits/stdc++.h>

#include "robot.hpp"
using namespace std;

extern unsigned money, boat_capacity, Frameid;
extern Berth berth[berth_num];
extern Boat boat[10];
extern char ch[Size + 10][Size + 10];
extern char berthRoute[Size + 10][Size + 10];

void BerthRoute() {  // 1234:RLUD
  queue<pair<unsigned, unsigned> > a;
  for (unsigned i(0); i < berth_num; ++i) {
    for (unsigned x(berth[i].x + 3); x >= berth[i].x; --x)
      for (unsigned y(berth[i].y + 3); y >= berth[i].y; --y)
        a.push({x, y}), berthRoute[x][y] = 10 + i;
  }
  while (a.size()) {
    unsigned Curx(a.front().first), Cury(a.front().second);
    a.pop();
    if ((ch[Curx + 1][Cury] == '.' || ch[Curx + 1][Cury] == 'A') &&
        (!berthRoute[Curx + 1][Cury])) {
      berthRoute[Curx + 1][Cury] = 3, a.push({Curx + 1, Cury});
    }
    if ((ch[Curx - 1][Cury] == '.' || ch[Curx - 1][Cury] == 'A') &&
        (!berthRoute[Curx - 1][Cury])) {
      berthRoute[Curx - 1][Cury] = 4, a.push({Curx - 1, Cury});
    }
    if ((ch[Curx][Cury - 1] == '.' || ch[Curx][Cury - 1] == 'A') &&
        (!berthRoute[Curx][Cury - 1])) {
      berthRoute[Curx][Cury - 1] = 1, a.push({Curx, Cury - 1});
    }
    if ((ch[Curx][Cury + 1] == '.' || ch[Curx][Cury + 1] == 'A') &&
        (!berthRoute[Curx][Cury + 1])) {
      berthRoute[Curx][Cury + 1] = 2, a.push({Curx, Cury + 1});
    }
  }
  /*
  for (unsigned i(1); i <= 200; ++i) {
    for (unsigned j(1); j <= 200; ++j) {
      char Cur(berthRoute[i][j]);
      fprintf(stderr, "%c", Cur >= 10 ? 'a' + Cur - 10 : '0' + Cur);
    }
    fprintf(stderr, "\n");
  }
  */
}

void Init() {
  for (unsigned i(1); i <= Size; i++) scanf("%s", ch[i] + 1);  // Map [1, n]
  for (unsigned i(0); i < robot_num; i++) robot[i].Num = i, robot[i].Land = '.';
  for (unsigned i(0); i < 5; i++) boat[i].when_to_go = 0, boat[i].num = i;
  for (unsigned i(0); i < berth_num; i++) {
    unsigned Berid;
    scanf("%u", &Berid);
    berth[Berid].Input();
  }
  BerthRoute();
  scanf("%d", &boat_capacity);  // Same capacity
  char okk[100];
  scanf("%s", okk);
  printf("OK\n");
  fflush(stdout);
}

#endif