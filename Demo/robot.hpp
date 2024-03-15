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
char Order[4] = {0, 1, 2, 3};
char CntStep = 0;

struct Robot {
  unsigned x, y, Good, Num;
  char status;
  Robot() {}
  Robot(unsigned startX, unsigned startY) {
    x = startX;
    y = startY;
  }
  void Go(unsigned Dire) {  // 0123: RLUD
    if (Dire > 3 || CntStep > 3) {
      CntStep = 0;
      return;
    }
    ++CntStep;
    unsigned Newx(x + Delta[Dire][0]), Newy(y + Delta[Dire][1]);
    if (RobotFrame[Newx][Newy] >= Frameid) {
      // fprintf(stderr, "Bot %u Turn %u\n", Num, CntStep);
      return Go((Dire + 1) & 3);
    }
    RobotFrame[Newx][Newy] = Frameid + 1;
    printf("move %u %u\n", Num, Dire);
    RobotFrame[x][y] = 0, CntStep = 0;
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
    random_shuffle(Order, Order + 4);
    for (char i(3); ~i; --i) {
      unsigned Newx(x + Delta[Order[i]][0]), Newy(y + Delta[Order[i]][1]);
      if (RobotFrame[Newx][Newy] < Frameid)
        Cur[Newx][Newy] = Order[i] + 1, a.push({Newx, Newy});
    }
    while (a.size()) {
      unsigned Curx(a.front().first), Cury(a.front().second);
      // fprintf(stderr, "Cur (%u, %u)\n", Curx, Cury);
      char CurDire(Cur[Curx][Cury]);
      if (gds[Curx][Cury] >= ValAvr) return CurDire - 1;
      a.pop();
      if ((ch[Curx][Cury + 1] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx][Cury + 1])) {
        Cur[Curx][Cury + 1] = CurDire, a.push({Curx, Cury + 1});
      }
      if ((ch[Curx][Cury - 1] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx][Cury - 1])) {
        Cur[Curx][Cury - 1] = CurDire, a.push({Curx, Cury - 1});
      }
      if ((ch[Curx - 1][Cury] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx - 1][Cury])) {
        Cur[Curx - 1][Cury] = CurDire, a.push({Curx - 1, Cury});
      }
      if ((ch[Curx + 1][Cury] == '.' || ch[Curx][Cury + 1] == 'B') &&
          (!Cur[Curx + 1][Cury])) {
        Cur[Curx + 1][Cury] = CurDire, a.push({Curx + 1, Cury});
      }
    }
    return 4;
  }
};
#endif
