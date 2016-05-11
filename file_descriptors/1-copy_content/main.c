#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

#define BUFF_SIZE 4096

int main(int ac, char **av) {
  int fd, fd2, len;
  char buffer[BUFF_SIZE + 1];
  /* handles error of too few arguments */
  if (ac != 3) {
    return (1);
  }
  /* opens file to copy then opens destination file, truncates it if it exists or creates it if it doesn't exist */
  fd = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDWR | O_TRUNC | O_CREAT, 0644);
  if (fd == -1) {
    perror("open1");
    return (1);
  }
  if (fd2 == -1) {
    perror("open2");
    return (1);
  }
  /* stores contents of file to copy in buffer */
  len = read(fd, buffer, BUFF_SIZE);
  if (len == -1) {
    close(fd);
    return (1);
  }
  buffer[len] = '\0';
  write(fd2, buffer, len);
  close(fd);
  close(fd2);
  return (0);
}
