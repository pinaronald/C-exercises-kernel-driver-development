/* strlen: return the length of a string */

int strlen(char s[])
{
	int i=0;
	
	while ( s[i] != '\0')
		++i;

	return i;
}
