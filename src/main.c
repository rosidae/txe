#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "geo.h"
#include "tux.h"

int main() {
  clearscreen();
  wait_for_input();
  printf("You pressed: %c\n", *(char*)get_last_output());
  return 0;
}