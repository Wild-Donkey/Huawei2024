#include <bits/stdc++.h>
using namespace std;

const int n = 200;
const int robot_num = 10;
const int berth_num = 10;
const int N = 210;

struct Robot {
  int x, y, goods;
  int status;
  int mbx, mby;
  Robot() {}
  Robot(int startX, int startY) {
    x = startX;
    y = startY;
  }
} robot[robot_num + 10];

struct Berth {              // Berth to berth 50000 frames.
  unsigned x;               // [x, x + 3]
  unsigned y;               // [y, y + 3]
  unsigned transport_time;  // berth <-> dest
  unsigned loading_speed;   // Obj per frame
  unsigned Obj              // Number of objects
  Berth() {}
  Berth(unsigned x, unsigned y, unsigned transport_time,
        unsigned loading_speed) {
    this->x = x;
    this->y = y;
    this->transport_time = transport_time;
    this->loading_speed = loading_speed;
  }
} berth[berth_num + 10];

struct Boat {
  unsigned num;
  int pos;          //-1 For destination
  unsigned status;  // 0 for moving, 1 for loading or available, 2 for queuing
} boat[10];

struct Command {
  unsigned Type;  // 0: Move, 1: Get, 2: Pull, 3: Ship, 4: Go
  int Arg1, Arg2;
  inline void Prt() {
    switch (Type) {
      case 0:
        printf("move %d %d\n", Arg1, Arg2);
        break;
      case 1:
        printf("get %d\n", Arg1);
        break;
      case 2:
        printf("pull %d\n", Arg1);
        break;
      case 3:
        printf("ship %d %d\n", Arg1, Arg2);
        break;
      case 4:
        printf("go %d\n", Arg1);
        break;
    }
  }
} CmdList[105], CntCmd;

int money, boat_capacity, Frameid;
char ch[N][N];  //'.'land, '*', '#', Don't across
int gds[N][N];
void Init() {
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);  // Map [1, n]
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

int Input() {
  scanf("%d%d", &Frameid, &money);
  int num;
  scanf("%d", &num);
  for (int i = 1; i <= num; i++) {
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

int main() {
  Init();
  for (unsigned Frame = 1; Frame <= 15000; Frame = Frameid + 1) {
    unsigned Frameid = Input();
    CntCmd = 0;
    for (unsigned i = 1; i <= CntCmd; ++i) CmdList[i].Prt();
    puts("OK");
    fflush(stdout);
  }

  return 0;
}
