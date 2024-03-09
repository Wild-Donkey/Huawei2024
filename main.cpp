#include <bits/stdc++.h>

#include "arrange.hpp"
#include "berth.hpp"
#include "boat.hpp"
#include "command.hpp"
#include "navigation.hpp"
#include "robot.hpp"

using namespace std;

extern const int n = 200, N = 210;
extern const int robot_num = 10;
extern const int berth_num = 10;

Berth berth[berth_num + 10];
Robot robot[robot_num + 10];
Boat boat[10];
Command CmdList[105];

unsigned CntCmd;
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
/*
g++ main.cpp -o main
*/