#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

#define BUFF_SIZE 4096

int print_char(char c);

int main(int ac, char **av) {
  struct stat buffer;
  /* handles error of too few arguments */
  if (ac < 2) {
    return (1);
  }
  if (lstat(av[1], &buffer) == -1) {
    return (1);
  }
  else {
    /* checks if argument is a directory */
    write(1, (S_ISDIR(fileStat.st_mode)) ? "d" : "-", 1);
    /* checks user permissions */
    write(1, (fileStat.st_mode & S_IRUSR) ? "r" : "-", 1);
    write(1, (fileStat.st_mode & S_IWUSR) ? "w" : "-", 1);
    write(1, (fileStat.st_mode & S_IXUSR) ? "x" : "-", 1);
    /* checks group permissions */
    write(1, (fileStat.st_mode & S_IRGRP) ? "r" : "-", 1);
    write(1, (fileStat.st_mode & S_IWGRP) ? "w" : "-", 1);
    write(1, (fileStat.st_mode & S_IXGRP) ? "x" : "-", 1);
    /* checks other user permissions */
    write(1, (fileStat.st_mode & S_IROTH) ? "r" : "-", 1);
    write(1, (fileStat.st_mode & S_IWOTH) ? "w" : "-", 1);
    write(1, (fileStat.st_mode & S_IXOTH) ? "x" : "-", 1);
    write(1, "\n", 1);    
  }
  return (0);
}
