#define berth_num 10
#define robot_num 10
#define Size 200

#include <bits/stdc++.h>

#include "arrange.hpp"
#include "berth.hpp"
#include "boat.hpp"
#include "command.hpp"
#include "frame.hpp"
#include "init.hpp"
#include "navigation.hpp"
#include "robot.hpp"

using namespace std;

Berth berth[berth_num + 10];
Robot robot[robot_num + 10];
Boat boat[10];

unsigned money, boat_capacity, Frameid;
char ch[Size + 10][Size + 10];  //'.'land, '*', '#', Don't across
int gds[Size + 10][Size + 10];

int main() {
  Init();
  for (unsigned Frame = 1; Frame <= 15000; Frame = Frameid + 1) Play();

  return 0;
}
/*
g++ main.cpp -o main
*/