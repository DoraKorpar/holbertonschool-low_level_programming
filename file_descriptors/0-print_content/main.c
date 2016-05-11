#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 4096

int print_char(char c);

int main(int ac, char **av) {
  int fd, len, i;
  char buffer[BUFF_SIZE + 1];
  /* handles error if there aren't enough arguments */
  if (ac < 2) {
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

  buffer[len] = '\0';
  i = 0;
  while (buffer[i] != '\0') {
    print_char(buffer[i]);
    i++;
  }
  close(fd);
  return (0);
}
