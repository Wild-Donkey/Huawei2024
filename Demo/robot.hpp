#ifndef MY_ROBOT
#define MY_ROBOT
#include <bits/stdc++.h>

using namespace std;

extern char ch[Size + 10][Size + 10];
extern unsigned gds[Size + 10][Size + 10];
extern short RobotFrame[Size + 10][Size + 10];
extern unsigned ValAvr;

const char Delta[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
const char Dire[5] = "RLUD";

inline char check(unsigned x,
                  unsigned y) {  // 0: Land, 1: Don't, 2: Good, 3: Berth
  if (gds[x][y] > 0) return 2;
  if (ch[x][y] == '.') return 0;
  if (ch[x][y] == 'B') return 3;
  return 1;
}

struct Robot {
  unsigned x, y, Good, Num;
  char status, Land;
  Robot() {}
  Robot(unsigned startX, unsigned startY) {
    x = startX;
    y = startY;
  }
  inline void Go(unsigned Dire) {  // 0123: RLUD
    if (Dire < 4) {
      unsigned Newx(x + Delta[Dire][0]), Newy(y + Delta[Dire][1]);
      if (RobotFrame[Newx][Newy] >= Frameid) return;
      RobotFrame[Newx][Newy] = Frameid + 1;
      printf("move %u %u\n", Num, Dire);
    }
  }
  inline void Get() { printf("get %u\n", Num); }
  inline void Drop() {
    // fprintf(stderr, "Bot %u Drop %u (%u, %u)\n", Num, Good, x, y);
    berth[berthRoute[x][y] - 10].Get(Good), Good = 0;
    printf("pull %u\n", Num);
  }
  char InBerth() { return berthRoute[x][y] >= 10; }
  char SearchBerth() {  // 0123: RLUD, 4: Stop
    // fprintf(stderr, "Robot %u (%u, %u)Go %u\n", Num, x, y,
    // berthRoute[x][y]);
    if (InBerth()) return 4;
    if (!berthRoute[x][y]) return 4;
    return berthRoute[x][y] - 1;
  }
  char SearchGood() {  // 0123: RLUD, 4: Stop
    // fprintf(stderr, "%u SearchGood (%u, %u)\n", Num, x, y);
    if (gds[x][y] >= ValAvr) {
      Get();
      Good = gds[x][y];
      gds[x][y] = 0;
      return SearchBerth();
    }
    char Cur[201][201];
    memset(Cur, 0, sizeof(Cur));
    queue<pair<unsigned, unsigned> > a;
    Cur[x][y] = 5;
    if ((ch[x][y + 1] == '.' || ch[x][y + 1] == 'B') &&
        (RobotFrame[x][y + 1] < Frameid))
      Cur[x][y + 1] = 1, a.push({x, y + 1});
    if ((ch[x][y - 1] == '.' || ch[x][y - 1] == 'B') &&
        (RobotFrame[x][y - 1] < Frameid))
      Cur[x][y - 1] = 2, a.push({x, y - 1});
    if ((ch[x - 1][y] == '.' || ch[x - 1][y] == 'B') &&
        (RobotFrame[x - 1][y] < Frameid))
      Cur[x - 1][y] = 3, a.push({x - 1, y});
    if ((ch[x + 1][y] == '.' || ch[x + 1][y] == 'B') &&
        (RobotFrame[x + 1][y + 1] < Frameid))
      Cur[x + 1][y] = 4, a.push({x + 1, y});
    while (a.size()) {
      unsigned Curx(a.front().first), Cury(a.front().second);
      // fprintf(stderr, "Cur (%u, %u)\n", Curx, Cury);
      char CurDire(Cur[Curx][Cury]);
      if (gds[Curx][Cury] >= ValAvr) return CurDire - 1;
      a.pop();
      if ((ch[Curx][Cury + 1] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx][Cury + 1]) && (RobotFrame[Curx][Cury + 1] < Frameid)) {
        Cur[Curx][Cury + 1] = CurDire, a.push({Curx, Cury + 1});
      }
      if ((ch[Curx][Cury - 1] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx][Cury - 1]) && (RobotFrame[Curx][Cury - 1] < Frameid)) {
        Cur[Curx][Cury - 1] = CurDire, a.push({Curx, Cury - 1});
      }
      if ((ch[Curx - 1][Cury] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx - 1][Cury]) && (RobotFrame[Curx - 1][Cury] < Frameid)) {
        Cur[Curx - 1][Cury] = CurDire, a.push({Curx - 1, Cury});
      }
      if ((ch[Curx + 1][Cury] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx + 1][Cury]) && (RobotFrame[Curx + 1][Cury] < Frameid)) {
        Cur[Curx + 1][Cury] = CurDire, a.push({Curx + 1, Cury});
      }
    }
    return 4;
  }
};
#endif
