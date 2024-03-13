#ifndef MY_ROBOT
#define MY_ROBOT
#include <bits/stdc++.h>

using namespace std;

extern char ch[Size + 10][Size + 10];
extern unsigned gds[Size + 10][Size + 10];

const char Dire[5] = "RLUD";

inline char check(unsigned x,
                  unsigned y) {  // 0: Land, 1: Don't, 2: Good, 3: Berth
  if (gds[x][y] > 0) return 2;
  if (ch[x][y] == '.') return 0;
  if (ch[x][y] == 'B') return 3;
  return 1;
}

struct Robot {
  unsigned x, y, goods, Num;
  int status;
  Robot() {}
  Robot(unsigned startX, unsigned startY) {
    x = startX;
    y = startY;
  }
  inline void Go(unsigned Dire) {  // 0123: RLUD
    printf("move %u %u\n", Num, Dire);
  }
  inline void Get() { printf("get %u\n", Num); }
  inline void Drop() { printf("pull %u\n", Num); }
  char SearchBerth() { return 1; }
  char SearchGood() {  // 0123: RLUD, 4: Stop
    if (gds[x][y] > 0) {
      Get();
      goods = gds[x][y];
      gds[x][y] = 0;
      return SearchBerth();
    }
    char Cur[201][201];
    memset(Cur, 0, sizeof(Cur));
    queue<pair<unsigned, unsigned> > a;
    Cur[x][y] = 5;
    Cur[x + 1][y] = 1;
    Cur[x - 1][y] = 2;
    Cur[x][y - 1] = 3;
    Cur[x][y + 1] = 4;
    a.push({x + 1, y});
    a.push({x - 1, y});
    a.push({x, y - 1});
    a.push({x, y + 1});
    while (a.size()) {
      unsigned Curx(a.front().first), Cury(a.front().second);
      char CurDire(Cur[Curx][Cury]);
      a.pop();
      if (ch[Curx + 1][Cury] == '.' && (!Cur[Curx + 1][Cury])) {
        if (gds[Curx + 1][Cury] > 0) return CurDire;
        Cur[Curx + 1][Cury] = CurDire, a.push({x + 1, y});
      }
      if (ch[Curx - 1][Cury] == '.' && (!Cur[Curx - 1][Cury])) {
        if (gds[Curx - 1][Cury] > 0) return CurDire;
        Cur[Curx - 1][Cury] = CurDire, a.push({x - 1, y});
      }
      if (ch[Curx][Cury - 1] == '.' && (!Cur[Curx][Cury - 1])) {
        if (gds[Curx][Cury - 1] > 0) return CurDire;
        Cur[Curx][Cury - 1] = CurDire, a.push({x, y - 1});
      }
      if (ch[Curx][Cury + 1] == '.' && (!Cur[Curx][Cury + 1])) {
        if (gds[Curx][Cury + 1] > 0) return CurDire;
        Cur[Curx][Cury + 1] = CurDire, a.push({x, y + 1});
      }
    }
    return 4;
  }
};
#endif
