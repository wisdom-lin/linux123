//============================================================================
// Name        : strandard_c.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//itoa
//atoi
//strcpy
//strcat
//strstr
//strcmp
//strtok
int _strlen(const char* s)
{
	const char *p  = s;
	for(;*s != '\0';s++);
	return s-p;
}

char* strchr(const char* s,char ch)
{
	for(;*s != '\0';s++)
		if(*s == ch)
			return (char*)s;
	return NULL;

}

int _strcmp(const char * s1,const char * s2)
{
	if(s1 == NULL && s2 == NULL)
		return 0;
	if(s1 == NULL)
		return -1;
	if(s2 == NULL)
		return 1;
	for(;*s1 == *s2 && *s1 != '\0';s1++,s2++);
	if(*s1 == *s2 && *s1 == '\0')
		return 0;

	return *(unsigned char*)s1 > *(unsigned char*)s2 ? 1 : -1;

}

int _strncmp(const char*s1,const char* s2,size_t len)
{
	if(s1 == NULL && s2 == NULL)
		return 0;
	if(s1 == NULL)
		return -1;
	if(s2 == NULL)
		return 1;
	//?NULL
	for(;len>0;len--,s1++,s2++)
	{
		if(*s1 != *s2)
			return *(unsigned char*)s1 > *(unsigned char*)s2 ? 1 : -1;
		else if(*s1 == '\0')
			return 0;
	}
	return 0;
}

char * _strcpy(char* dst,const char * src)
{
	if(dst == NULL || src == NULL)
		return NULL;
	char *p = dst;
	for(;*src != '\0';dst++,src++)
		*dst = *src;
	*dst = '\0';
	return p;
}

char* _strncpy(char * dst,const char* src,size_t len)
{
	if(dst == NULL || src == NULL)
		return NULL;
	char *p = dst;
	for(;len>0 && *src != '\0';len--,dst++,src++)
		*dst = *src;
	for(;len>0;len--,dst++)
		*dst = '\0';
	return p;
}

char* _strcat(char * dst,const char * src)
{
	if(dst == NULL || src == NULL)
		return NULL;
	char *p = dst;
	for(;*dst != '\0';dst++);
	for(;*src !='\0';src++,dst++)
		*dst = *src;
	*dst = '\0';
	return p;
}

char* _strncat(char* dst,const char* src,size_t len)
{
	if(dst == NULL || src == NULL)
		return NULL;
	char *p = dst;
	for(;*dst != '\0';dst++);
	for(;len>0 & *src != '\0';len--,dst++,src++)
		*dst = *src;
	*dst = '\0';
	return p;
}

void* _memncpy(void * dst,const void * src,size_t len)
{
	char * ch1 = (char*)dst;
	const char* ch2 = (char*)src;

	for(;len>0;len--,ch1++,ch2++)
		*ch1 = *ch2;
	return dst;
}

void* _memmove(void * dst,const void * src,size_t len)
{
	char* s1 = (char*)dst;
	const char* s2 = (const char*)src;

	if(s1 > s2 && s1 < s2 + len)
		for(s1+=len,s2+=len;len>0;len--)
			*--s1 = *--s2;
	else
		for(;len>0;len--)
			*s1++ = *s2++;

	return dst;
}

void* _memset(void* src,int c,size_t len)
{
	const unsigned char  uc =c ;
	unsigned char* su = (unsigned char*)src;

	for(;len>0;len--)
		*su++  = uc;
	return src;
}

int _memcmp(const void * s1,const void * s2,size_t len)
{
	const unsigned char* sc1 = (const unsigned char*)s1;
	const unsigned char* sc2 = (const unsigned char*)s2;
	for(;len> 0; len--,sc1++,sc2++)
	if(*sc1 != *sc2)
		return *sc1 >  *sc2 ? 1 : -1;
	return 0;
}

void* _memchr(const void* s,int c,size_t len)
{
	const unsigned char* sc = (const unsigned char*)s;
	unsigned char uc = (unsigned char)c;
	for(;len>0;len--,sc++)
			if(*sc == uc)
				return (void*)sc;
	return NULL;

}


float _atof(const char* s)
{
	if(s == NULL)
		return 0;


	for(;isspace(*s);s++);

	int sign = 1;
	if(*s == '-')
	{
		s++;
		sign = -1;
	}
	else if(*s == '+')
	{
		s++;
	}
	float val = 0.0;

	for(;isdigit(*s);s++)
	{
		val = val * 10 + (*s - '0');
	}

	if(*s == '.')
		s++;

	int power = 1;
	for(;isdigit(*s);s++)
	{
		val = val * 10 + (*s - '0');
		power *= 10;
	}
	return sign * val  / power;
}

int _atoi(const char* s)
{
	return (int)_atof(s);
}

char* _itoa(int val,char * ch)
{

	int i = 0;
	int sign = 0;
	if(val <0)
	{
		val *= -1;
		sign = -1;
	}

	do
	{
		ch[i++] = val%10 + '0';
		val/=10;
	}while(val != 0);

	if(sign <0)
		ch[i++] = '-';

	//reverse

	ch[i] = '\0';

	int beg = 0,end = i-1;
	for(;beg < end;beg++,end--)
	{
		char c = ch[beg];
		ch[beg] = ch[end];
		ch[end] = c;
	}

	return ch;
}

char* _ftoa(float val,char * ch)
{
	if(val == 0)
	{
		ch[0] = '0';
		ch[1] = '\0';
		return ch;
	}

	int flag = 1;
	if(val < 0)
	{
		flag = -1;
		val *= -1;
	}



}

int main() {

//	cout << _strcmp("abc",NULL) << endl;
//	cout << _strcmp("abc1","abc") << endl;
//	cout << _strcmp("abc","abc1") << endl;
//	cout << _strcmp("","") << endl;
//	cout << _strcmp("","abc") << endl;
//	cout << _strcmp("abc","") << endl;

//	cout << _strncmp("abc","abc",6) << endl;
//	cout << _strncmp("abc",NULL,1) << endl;
//	cout << _strncmp("abc1","abc",4) << endl;
//	cout << _strncmp("abc1","abc",3) << endl;
//	cout << _strncmp("abc1","abc",5) << endl;
//	cout << _strncmp("abc","abc1",2) << endl;
//	cout << _strncmp("abc","abc1",4) << endl;
//	cout << _strncmp("abc","abc1",5) << endl;
//	cout << _strncmp("","",0) << endl;
//	cout << _strncmp("","",1) << endl;
//	cout << _strncmp("","abc",1) << endl;
//	cout << _strncmp("","abc",2) << endl;
//	cout << _strncmp("","abc",3) << endl;
//	cout << _strncmp("abc","",0) << endl;
//	cout << _strncmp("abc","",1) << endl;
//	cout << _strncmp("abc","abc",1) << endl;
//	cout << _strncmp("abc","abc",3) << endl;
//	cout << _strncmp("abc","abc",0) << endl;
//	cout << _strncmp("abc","abc",4) << endl;
//	cout << _strncmp("abc","a",2) << endl;
//	cout << _strncmp("abc","a",1) << endl;
//	cout << _strncmp("abc","a",4) << endl;

//	char d[20];
//	cout << _strcpy(d,"1231421") << endl;
//	memset(d,0,20);
//	cout << _strcpy(d,"") << endl;
//	memset(d,0,20);
//	cout << _strcpy(d,"1") << endl;
//
//	memset(d,0,20);
//	cout << _strncpy(d,"112",2) << endl;
//	memset(d,0,20);
//	cout << _strncpy(d,"112",4) << endl;
//	memset(d,0,20);
//	cout << _strncpy(d,"112",0) << endl;
//	memset(d,0,20);
//	cout << _strncpy(d,"112",3) << endl;





//	char s[30] = "123455";
//	cout << _strcat(s,"abc") << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strcat(s,"") << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strcat(_strcat(s,"kk"),"a") << endl;
//
//
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(s,"",0) << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(s,"",1) << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(s,"123123",6) << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(s,"123123",7) << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(s,"123123",3) << endl;
//	strncpy(s,"123455",strlen("123455")+1);
//	cout << _strncat(_strncat(s,"dd",2),"io",2) << endl;
//
//	cout << _strstr("abcabcd","abc") << endl;
//	cout << _strstr("abc1abcd","c1a") << endl;
//	cout << _strstr("abd1abcd","abc") << endl;
//	cout << _strstr("abc1abcd","d") << endl;
//	cout << _strstr("1aabcd","a") << endl;
//	cout << _strstr("1abcabcd","abcd") << endl;
//	cout << _strstr("1abcabcd","") << endl;
//	string ss;
//	cout << (ss = _strstr("","asdf") == NULL ? string("null"):string("not null")) << endl;
//	cout << (ss = _strstr("kkoiu","asdf") == NULL ? string("null"):string("not null"))  << endl;
//	cout << _strstr("kkkkkk","kkkkkk") << endl;

//	char ch[20];
//	memset(ch,0,20);
//	cout << (char*)_memset(ch,97,19) << endl;
//	memset(ch,0,20);
//	cout << (char*)_memset(ch,97,1) << endl;
//	memset(ch,0,20);
//	cout << (char*)_memset(ch,97,0) << endl;

//	char ch[20];
//	cout << (char*)_memncpy(ch,"1234",10)<< endl;
//	memset(ch,0,20);
//	cout << (char*)_memncpy(ch,"1234",1)<< endl;
//	memset(ch,0,20);
//	cout << (char*)_memncpy(ch,"1234",0)<< endl;
//	memset(ch,0,20);
//	cout << (char*)_memncpy(ch,"1234",4)<< endl;

//	char ch[20];
//	memset(ch,0,20);
//	cout << (char*)_memmove(ch,"123132",4) << endl;
//	memset(ch,0,20);
//	cout << (char*)_memmove(ch,"123132",0) << endl;
//	memset(ch,0,20);
//	cout << (char*)_memmove(ch,"123132",7) << endl;
//
//	char ss[20] = "1234567891234";
//	cout << (char*)_memmove(ss+3,ss,4) << endl;
//	memset(ss,0,sizeof(ss));
//	cout << (char*)_memmove(ss+3,ss,6) << endl;
//	memset(ss,0,sizeof(ss));
//	cout << (char*)_memmove(ss+3,ss,1) << endl;


//	cout << _memcmp("123","1234",1) << endl;
//	cout << _memcmp("123","1234",4) << endl;
//	cout << _memcmp("123","1234",5) << endl;

//	cout << (char*)_memchr("1231",'1',4) << endl;
//	cout << (char*)_memchr("1234",'4',3) << endl;
//	cout << (char*)_memchr("1235",'d',4) << endl;

//	cout << _atoi(" 123") << endl;
//	cout << _atoi(" -123") << endl;
//	cout << _atoi("0") << endl;
//	cout << _atoi(" 1.7") << endl;
//
//	cout << _atof("123") << endl;
//	cout << _atof(" -123") << endl;
//	cout << _atof("0") << endl;
//	cout << _atof("10.7") << endl;
//	cout << _atof(" -10.7") << endl;
//	cout << _atof(" -1.67") << endl;
//	cout << _atof("-0.67") << endl;
//	cout << _atof(" 0.67") << endl;

	char ch[20] = {0};
	cout << _itoa(123,ch) << endl;
	memset(ch,0,20);
	cout << _itoa(-123,ch) << endl;
	memset(ch,0,20);
	cout << _itoa(0,ch) << endl;
	memset(ch,0,20);
	cout << _itoa(-0,ch) << endl;


	return 0;
}

