// tux.h - terminal user interface/terminal user experience
#pragma once
#include "geo.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct v2 getxy() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return (struct v2){w.ws_col, w.ws_row};
}

void clearscreen() {
  printf("\033[2J"); 
}

void wait_for_input() {
  getchar();
}