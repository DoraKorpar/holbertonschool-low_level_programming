#include <stdlib.h>
#include <unistd.h>
int (*get_op_func(char c))(int, int);
int print_char(char c);
void print_number_pos(int n);
void print_number(int n);

int main(int ac, char ** av) {
  int num1, num2, answer;
  
  if (ac != 4) {
   return 1;
  }
  else if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*' && av[2][0] != '/' && av[2][0] != '%') {
    return 1;
  }
  else if (av[2][1] != '\0') {
    return 1;
  }
  else { 
    num1 = atoi(av[1]);
    num2 = atoi(av[3]);
    answer = (get_op_func(av[2][0]))(num1, num2);    
    print_number(answer);
    print_char('\n');
    }
  return 0;
}

int print_char(char c) {
  return (write(1, &c, 1));
}

void print_number(int n) {
  if (n > 0) {
      print_number_pos(n);
    }
  if (n == 0) {
      print_char('0');
    }
  if (n < 0) {
      n = -n;
      print_char('-');
      print_number_pos(n);
    }
}

void print_number_pos(int n) {
  int n2 = n;
  int power = 1;
  int print;
  while (n2 > 9) {
      n2 /= 10;
      power *= 10;
    }
  while (n > 0) {
      print = n / power;
      n = n % power;
      power /= 10;
      print_char(print + 48);
    }
}
