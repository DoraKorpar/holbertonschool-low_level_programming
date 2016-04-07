/* uses ASCII number codes to convert lowercase letters to uppercase */
char uppercase(char c)
{
  if (c >= 97 && c <= 122) {
    return(c - 32);
  }
  else {
    return(c);
  }
}  
