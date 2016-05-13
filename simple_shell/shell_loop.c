#include <unistd.h>
#include <stdio.h>
#include "libshell.h"

int print_char(char c);
void (*get_func(char *str))(char **env);

void shell_loop(char **env)
{
  void (*func_ptr)(char **env);
  char **args;
  char *line;
  char str[21] = "D&J's_awesome_prompt";
  int i;
  int j;
  j = 0;

  /* prints prompt string continually */
  while (1) {
    for (i = 0; str[i] != '\0'; ++i) {
      print_char(str[i]);
    }
    print_char('$');
    print_char(' ');

    /* read_line stores string of everything typed in terminal and string_split parses it */
    line = read_line(0);
    args = string_split(line, ' ');
    
    while (args[j]) {
      ++j;
    }
    if (j > 1) {
      perror("Error: This command takes no arguments");
    } else {
      func_ptr = get_func(args[0]);
      (*func_ptr)(env);
    }
  }
}
