#include "fileSearcher.h"

uint16_t MaximumNumberOfFiles = 10;

//char *FileList[MaximumNumberOfFiles];
char *FileList[100];

uint8_t isACFile(char *_fileName)
  {
  char *fileExtension = strrchr(_fileName, '.');
  return ((fileExtension) && strcmp(fileExtension, ".c") == 0);
  }

uint8_t FindAllCFiles(char *_startingDirectory)
  {
  DIR *directory = opendir(_startingDirectory);

  if (NULL == directory)
    {
    //printf("Failed to search the submitted directory: %s\n", _startingDirectory);
    fprintf(stderr, "Cannot open directory %s: %s\n", _startingDirectory, strerror(errno));
    return 1;
    }
  
  struct dirent *entry;
  struct stat statBuf;
  char fullFilePath[MAX_PATH_SIZE];

  while (entry = readdir(directory))
    {
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
      {
      continue;
      }
    snprintf(fullFilePath, MAX_PATH_SIZE, "%s/%s", _startingDirectory, entry->d_name); 

    if (stat(fullFilePath, &statBuf) == -1)
      {
      fprintf(stderr, "Cannot stat %s: %s\n", fullFilePath, strerror(errno));
      continue;
      }

    if (S_ISDIR(statBuf.st_mode))
      {
      FindAllCFiles(fullFilePath);
      }
    else if (S_ISREG(statBuf.st_mode) && isACFile(entry->d_name))
      {
      printf("%s\n", fullFilePath);
      }
    }
  closedir(directory);
  }


//uint8_t InitializeFileList(int _numberOfFilesToStart)
//  {
//  uint8_t returnValue;
//
//  }
