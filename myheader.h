#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>




int main(int argc,char* argv[]);
int checkArg(int argc, char* argv[], char* arg);

#endif
