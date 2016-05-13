#include <stdio.h>
#include <unistd.h>

int string_compare(char *s1, char *s2);
void print_env(char **env);

void (*get_func(char *str))(char **env)
{
  char *command[] = {"env", "exit"};
  void (*func_addrs[])(char **) = {&print_env /*, &exit_shell */};
  int i;
  int comp;

  for (i = 0; command[i]; ++i) {
    comp = string_compare(str, command[i]);

    if (comp != 0) {
    perror("Error: That command is not recognized");
    } else {
      return (func_addrs[i]);
    }
  }
  return (0);
}
