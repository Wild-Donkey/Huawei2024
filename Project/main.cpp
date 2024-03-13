#define berth_num 10
#define robot_num 10
#define Size 200

#include <bits/stdc++.h>

unsigned money, boat_capacity, Frameid;
char ch[Size + 10][Size + 10];  //'.'land, '*', '#', Don't across
unsigned gds[Size + 10][Size + 10];

#include "berth.hpp"
Berth berth[berth_num];
#include "robot.hpp"
Robot robot[robot_num];
#include "boat.hpp"
Boat boat[10];
#include "arrange.hpp"
#include "command.hpp"
#include "frame.hpp"
#include "init.hpp"
#include "navigation.hpp"

using namespace std;

int main() {
  Init();
  for (unsigned Frame = 1; Frame <= 15000; Frame = Frameid + 1) Play();

  return 0;
}
/*
g++ main.cpp -o main
*/