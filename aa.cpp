int atoi(const char* s)
{
	if(s == NULL)
		return 0;
	int val = 0 ;
	int flag = 1;
	if(*s == '-')
		flag = -1;
	for(;*s != '\0';s++)
	{
		val *= 10;
		val += (*s  - '0');
	}
	return flag * val;
}

float atof(const char* s)
{
	if(s == NULL)
		return 0;
	int val = 0;
	int flag = 1;
	if(*s == '-')
		flag = -1;
	for(;*s != '\0' && *s != '.';s++)
	{
		val *= 10;
		val += (*s - '0');
	}
	if(*s == '0')

}
