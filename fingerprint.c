#include<stdio.h>
#include<string.h>
#include<math.h>
#include<dirent.h>          //A type representing a directory stream. 
#include "fingerprint.h"             //we get the result by including these header files which has function finger print. 

int main(int argc,char const *argv[])    //command line arguments for taking the path
{
	char filestr[100][30];
	DIR *d;                          //opendir function shall open a directory corresponding to it
	struct dirent *dir;
	chdir(argv[1]);
	d=opendir(argv[1]);
	int filescount=0;
	if (d)
	{
		while((dir=readdir(d))!=NULL)             //using while loop until d is not equal to zero
		{
			int m=strlen(dir->d_name);             //taking the files count so to know 
			if (((int)dir->d_name[m-1])==116&&((int)dir->d_name[m-2])==120&&((int)dir->d_name[m-3])==116)
			{
				strcpy(filestr[filescount],dir->d_name);
				filescount++;
			}
		}
	}
	int n;
	printf("s.n.o");             //taking this to show what to print
	int i;                   
	for (i=0;i<filescount;i++)
	{                                  
		printf("%15s",filestr[i]);    //printing the file name as per file count//      
	}
	FILE *fp;              
	int j,x,y;
	char c;                  
	for (i=0;i<filescount;i++)
	{
		printf("\n%s ",filestr[i]);  
		char string1[100];
		char string2[100];
		for (j=0;j<filescount;j++)
		{
			fp=fopen(filestr[i],"r");       //file operations 
			c=fgetc(fp);             
			int k=0;
			while (c!=EOF)             //until end of file we are taking 
			{
				string1[k]=c;     //storing that string1 
				c=fgetc(fp);
				k++;
			}
			string1[k]='\0';   //giving the end of string 1
			k=0;
			fp=fopen(filestr[j],"r"); //file operations
			c=fgetc(fp);
			while (c!=EOF) //until end of file we are taking          
			{
				string2[k]=c; //storing that string2   
				c=fgetc(fp); 
				k++;
			}
			string2[k]='\0';    //giving the end of string 2
			k=0;
			float p=fingerprint(string1,string2,4); //calling the function finger print to know the result  
			printf("%15f",p);     //printing that value and spacing between float  value is 15
		}
	}
	return 1;
}
