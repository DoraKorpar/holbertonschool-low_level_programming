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
    if (S_ISDIR(buffer.st_mode)) {
      print_char('d');
    }
    else {
      print_char('-');
    }
    /* checks user permissions */
    if (buffer.st_mode & S_IRUSR) {
      print_char('r');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IWUSR) {
      print_char('w');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IXUSR) {
      print_char('x');
    }
    else {
      print_char('-');
    }
    /* checks group permissions */
    if (buffer.st_mode & S_IRGRP) {
      print_char('r');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IWGRP) {
      print_char('w');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IXGRP) {
      print_char('x');
    }
    else {
      print_char('-');
    }
    /* checks other user permissions */
    if (buffer.st_mode & S_IROTH) {
      print_char('r');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IWOTH) {
      print_char('w');
    }
    else {
      print_char('-');
    }
    if (buffer.st_mode & S_IXOTH) {
      print_char('x');
    }
    else {
      print_char('-');
    }  
    print_char('\n');
  }
  return (0);
}
