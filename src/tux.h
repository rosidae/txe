// tux.h - terminal user interface/terminal user experience (tui doesn't roll off the tongue)
#pragma once
#include "geo.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

void* __glbuffer = NULL;

struct v2 getxy() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return (struct v2){w.ws_col, w.ws_row};
}

void clearscreen() {
  printf("\033[2J"); 
}

void wait_for_input() {
  int gc = getchar();
  __glbuffer = &gc;
}

void* get_last_output() {
  return __glbuffer;
}

struct box {
  struct v2 top_left;
  struct v2 bottom_right;
  struct v2 center_point;
  struct v2 size;
  char*     title;
};

