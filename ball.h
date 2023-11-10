#include <cmath>
#include <iostream>
#include <random>
#include <vector>

class Ball {
public:
  std::vector<float> vel;
  std::vector<float> pos;
  float r;
  Ball(float x, float y, float radius, float speed) {
    pos = {x,y};
    r = radius;
    int l = 5;
    int u = 5;
    vel = {speed, speed}; 
  }

  void update(int w, int h){
    pos[0] += vel[0];
    pos[1] += vel[1];
    if(pos[0] >= w || pos[0] < 0) vel[0] = -vel[0]; 
    if(pos[1] >= h || pos[1] < 0) vel[1] = -vel[1];
  }
};