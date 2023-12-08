#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int testdev;
  int i;
  char buf[50] = "pear to dev!";
  printf("program test is running!\n");
  testdev = open("/dev/mydev", O_RDWR);
  if (testdev == -1) {
    printf("can't open file \n");
    exit(0);
  }
  //向设备写入"pear to dev!"
  write(testdev, buf, 50);
  printf("write \"%s\"\n", buf, 50);
  //更改buf内容为"apple to dev!"
  strcpy(buf, "apple to dev!");
  printf("buffer is changed to \"%s\"", buf, 50);
  //由设备读出内容, 比较与buf不同
  read(testdev, buf, 50);
  printf("read from dev is \"%s\"\n", buf);
  //释放设备
  close(testdev);
}