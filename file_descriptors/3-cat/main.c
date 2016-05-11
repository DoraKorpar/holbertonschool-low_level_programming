#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFF_SIZE 4096

int print_content(char *);

int main(int ac, char **av) {
  char input;
  int i;

  if (ac < 2) {
    while ((read(0, &input, 1)) > 0) {
      write(1, &input, 1);
    }
  }

  i = 1;
  while (i < ac) {
    print_content(av[i]);
    i++;
  }
  return (0);
}

int print_content(char *fileName) {
  int fd, len;
  char buffer[BUFF_SIZE];

  fd = open(fileName, O_RDONLY);
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
