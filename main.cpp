#include "ball.h"
#include <iostream>
#include <math.h>
#include <sstream>
#include <thread>

using namespace std;

int main() {
  float speed;
  std::cout << "Enter an interger specifying simulation speed: ";
  std::cin >> speed;

  float d = 0;
  float y;
  float x;
  auto const w(WEXITSTATUS(std::system("exit `tput cols`")));
  auto const h(WEXITSTATUS(std::system("exit `tput lines`")));
  float n = (w * h) / 2500;
  std::vector<Ball> balls;
  int numBalls = 20;
  for (int i = 0; i < numBalls; i++) {
    balls.push_back(Ball(rand() % w, rand() % h, 1, speed / 5));
  }
  string out;
  std::stringstream ss;
  while (true) {
    for (float y = 1.0f; y < h; y++) {
      for (float x = 1.0f; x < w; x++) {
        float sum = 0.0f;
        for (auto &b : balls) {
          d = sqrt(pow(x - b.pos[0], 2) + pow(y - b.pos[1], 2) * 4);
          sum += 10 * balls[0].r / d;
        }
        if (sum < 4 / n) {
          out = " ";
        } else if (sum < 6 / n) {
          out = "@";
        } else if (sum < 8 / n) {
          out = "~";
        } else if (sum < 10 / n) {
          out = ".";
        } else {
          out = " ";
        }
        ss << out;
      }
      ss << "\033[1;31m" << endl;
    }
    for (auto &b : balls) {
      b.update(w, h);
    }
    cout << ss.str() << flush;
    ss.str("");
    ss.clear();
    this_thread::sleep_for(chrono::milliseconds(50));
    system("tput cup 0 0");
  }
  return 0;
}