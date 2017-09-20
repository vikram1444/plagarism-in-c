#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <dirent.h>            //A type representing a directory stream. 
#include "mal.h" //here we are using header file so that it returns euclidean and dot product
int fcount=0;
char file[20][100],name[20][100];
static void scan_dir(const char *dir)          //this function is for taking directory.
{
    struct dirent * entry;
    DIR *d = opendir( dir );                 //opendir function shall open a directory corresponding to it
    int c=0,ff=0;
    while ((entry = readdir(d)) != 0) 
    {
        if(c>1)
        {
            fcount+=1;                      //using while loop until d is not equal to zero
            strcpy(file[ff],dir);
            strcat(file[ff],entry->d_name);
            strcpy(name[ff],entry->d_name);
            printf("%s\n",file[ff]);
            ff+=1;
        }
        c+=1;
    }
    closedir(d);
}
int main(int argc,char const * argv[])       //command line arguments used for directly taking path
{
    //char str[100];
    //gets(str);
    scan_dir(argv[1]);                  //here argv[0] stores file name
    FILE *giga;
    float plagarism[fcount][fcount];
    int a,b;
    for(a=0;a<fcount;a++)                    //here using a,b variables so that the result is stored in matrix form
    {
        for(b=a;b<fcount;b++)
        {
            giga=fopen(file[a],"r");        //here we are doing file operations
            char line[1000],str[100];
            char bag[100][20];
            int x=0;
            while(!feof(giga)){               //using while loop until the end of file
                fscanf(giga,"%s",line);
                int z=0;
                for(int i=0;i<strlen(line);i++)
                {
                    if(isalpha(line[i]))
                    {
                        str[z]=line[i];    
                        z+=1;
                    }
                }
                str[z]='\0';
                strcpy(bag[x],str);          //taking bag of words in bag variable
                x+=1;
            }
            fclose(giga);               /*closing file operations */
            int i,k;
            char ee[100][100];
            int r=0,count=0,flag=0,wcount1[100],y=0; //declaring the required variables
            // printf("\n");
            for(i=0;i<x;i++)
            {
                for(k=0;k<r;k++)
                {                               
                    if(strcmp(bag[i],ee[k])==0)    //comparing bag of words and ee variable
                    {
                        count+=1;          // increasing the count so that we know that respective repetition
                    }
                }
                if(count==0)               
                {
                    for (int j = i; j < x; j++)
                    {
                        if (strcmp(bag[i], bag[j]) == 0) 
                        {
                            flag+=1;                   //again comparing if count is zero
                            strcpy(ee[r],bag[i]);  //string copy if count is zero and strcmp returns zero
                        }
                    }
                    wcount1[y]=flag;   //taking word count as flag value
                    y+=1;
                    r += 1;
                }
                flag=0;
                count=0;   //assigning the flag , count variables to zero
            }
            int len1=r;     //taking length into len1
            giga=fopen(file[b],"r");    //here we are doing file operations
            char line2[1000];
            char bag2[100][20];
            x=0;
            // printf("\n");
            while(!feof(giga)){        //using while loop until the end of file
                fscanf(giga,"%s",line2);
                int z=0;
                for(int i=0;i<strlen(line2);i++)
                {
                    if(isalpha(line2[i]))
                    {
                        str[z]=line2[i];
                        z+=1;
                    }
                }
                str[z]='\0';
                strcpy(bag2[x],str);             //taking bag of words in bag variable
                x+=1;
            }
            fclose(giga);               /*closing file operations */
             i=0,k=0,r=0,y=0,count=0,flag=0;
            char ee2[100][100];
            int wcount2[100];
            for(i=0;i<x;i++)
            {
                for(k=0;k<r;k++)
                {
                    if(strcmp(bag2[i],ee2[k])==0) //comparing bag of words and ee variable
                    {
                        count+=1;         // increasing the count so that we know that respective repetition
                    }
                }

                if(count==0)
                {
                    for (int j = i; j < x; j++)
                    {
                        if (strcmp(bag2[i], bag2[j]) == 0)
                        {
                            flag+=1;      //again comparing if count is zero

                        }
                    }
                    strcpy(ee2[r],bag2[i]); //copying word if count is zero
                    wcount2[y]=flag;        //string copy if count is zero and strcmp returns zero
                    y+=1;
                    r+=1;
                }
                flag=0;
                count=0;
            }
            int len2=r;               //taking length into len2
            double e1=euclidean(wcount1,len1); //calling euclidean with word count ,len1 variable as parameters
            double e2=euclidean(wcount2,len2); //calling euclidean with word count ,len1 variable as parameters
            double d=dot(wcount1,wcount2,ee,ee2,len1,len2); //getting dot product by sending respective parameters 
            double plag=d/(e1*e2);        //result in plag variable
            plag=plag*100;
            plagarism[a][b]=plag;   //storing plag value into plagarism variable
            plagarism[b][a]=plag;         
        }
    }
    printf("\nFile\t");        //this is used for displaying in file and matrix format
    int y=0;
    for(int i=0;i<fcount;i++)
    {
        printf("|%s\t",name[i] );  // '|'  used for displaying in better way
        y+=strlen(name[i]);
        y+=4;                      //y variable for spacing
    }
    printf("|");         
    printf("\n");
    for(int j=0;j<y;j++)
    {
        printf("=");               //using '= '  for gap between file name & result and y used for spacing

    }
   
    for(int i=0;i<fcount;i++)
    {
        printf("\n%s\t",name[i]); //using for loop to display in matrix form
        for(int j=0;j<fcount;j++)
        {
            printf("|%.2f\t",plagarism[i][j]);          //displaying the result stored in plagarism variable.
        }
        printf("|");                //used for keeping the gap between results.
    }
    printf("\n");
    for(int j=0;j<y;j++)
    {
        printf("=");                   //using '=' for better outlook.

    }

}

