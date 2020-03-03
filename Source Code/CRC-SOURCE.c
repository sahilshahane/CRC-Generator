#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "math.h"
#include "windows.h"
#define SIZE 1000000000

void append_degree();
void get_data();
void print_data();
int check_data();
void get_crc();
void xor_add(char[],int);

char data[SIZE],data2[SIZE],rem[SIZE];
int len,len2;

int main()
{
 system("color 0A");
 get_data();

	if(check_data()==0)
	 {
		 append_degree();
		 print_data();
		 get_crc();
	 }

 system("pause");
 return 0;
}


void get_data()
{
 int i;
 printf("Enter Data to be transferred : ");
 gets(data);

 printf("Enter Division data : ");
 gets(data2);

 len2 = strlen(data2);
}

void print_data()
{
 printf("\nData(appended) : %s\nDivisor : %s\n",data,data2);
}

int check_data()
{
int i;
	
  for(i=0;i<strlen(data);i++)
  if(data[i]>49)
    {
    	printf("\nError the Entered Data must be in the form of 0\'s and 1\'s");
    	return -1;
	}
  
  for(i=0;i<len2;i++)
  if(data2[i]>49)
    {
    	printf("\nError the Entered Data must be in the form of 0\'s and 1\'s");
    	return -1;
	}
  
  return 0;
}

void append_degree()
{
int i;
	for(i=0;i<len2 - 1;i++)
	strcat(data,"0");
	
 	len = strlen(data);
}

void get_crc()
{
int i;
	for(i=0;i<len2;i++)
	rem[i] = data[i];
	
	xor_add(rem,(rem[0]=='1'?1:0));

	for(i=0;i<len-len2;i++)
	{
		sprintf(rem,"%s%c",rem,data[i+len2]);
		xor_add(rem,(rem[0]=='1'?1:0));
	}
	
	printf("\nGENERATED CRC : %s\n\n",rem);
}

void xor_add(char temp[],int choice)
{
int i;
	char crc_temp[100]={"\0"};
	if(choice==1)
	for(i=1;i<len2;i++) //change to 0 for full remainder ONLY USE FOR DEBUG END RESULT WOULD BE DIFFERENT
		sprintf(crc_temp,"%s%d",crc_temp,(temp[i]-48)^(data2[i]-48));
	
	else
	for(i=1;i<len2;i++) //change to 0 for full remainder ONLY USE FOR DEBUG END RESULT WOULD BE DIFFERENT
		sprintf(crc_temp,"%s%d",crc_temp,(temp[i]-48)^0);
	
	strcpy(rem,crc_temp);
}
