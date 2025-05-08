#ifndef FILESEARCHER_H
#define FILESEARCHER_H

#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_PATH_SIZE 1024

uint8_t FindAllCFiles(char *_startingDirectory);

#endif //FILESEARCHER_H
