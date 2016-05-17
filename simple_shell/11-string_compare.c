int string_compare(char *s1, char *s2)
{
	int i;
	i = 0;
  	while (s1[i] == s2[i]) {
    		if (s1[i] == '\0' || s2[i] == '\0') {
      			break;
    		}
    		++i;
  	}
  	if (s1[i] == '\0' && s2[i] == '\0') {
    		return (0);
  	} else {
    		return (-1);
  	}
}
