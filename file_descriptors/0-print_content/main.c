#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 4096

int main(int ac, char **av) {
  int fd, len;
  char buffer[BUFF_SIZE];
  /* handles error if there aren't enough arguments */
  if (ac != 2) {
    return (1);
  }
  fd = open(av[1], O_RDONLY);
  if (fd == -1) {
    return (1);
  }
  
  len = read(fd, buffer, BUFF_SIZE);
  if (len == -1) {
    close(fd);
    return (1);
  }

  if ((write(1, buffer, len)) == -1) {
    close(fd);
    return (1);
  }
  close(fd);
  return (0);
}
