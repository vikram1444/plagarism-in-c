#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <dirent.h>            //A type representing a directory stream. 
#include "matc.h"              //here the result can be obtained by using matc.h header file
int fcount=0;
char file[20][100],name[20][100];
static void scan_dir(const char *dir)     //this function is for taking directory.
{
    struct dirent * entry;
    DIR *d = opendir( dir );          //opendir function shall open a directory corresponding to it
    int c=0,ff=0;                        
    while ((entry = readdir(d)) != 0) 
    {
        if(c>1)
        {
            fcount+=1;                 //using while loop until d is not equal to zero
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
int main(int argc,char const*argv[])         //command line arguments used for directly taking path
{
     scan_dir(argv[1]);                       //here argv[0] stores file name
    int p,q;
    float plagarism[fcount][fcount];
    for(p=0;p<fcount;p++)                       
    {
        for(q=p;q<fcount;q++)                 //here using p,q variables so that the result is stored in matrix form 
        {
            int z1,z2;
            printf("%s   %s\n",name[p],name[q]);
            FILE *giga;
            giga = fopen(file[p], "r");
            char line[1000], str[100];       //here we are doing file operations
            char bag[100][20];
            int x = 0,st=0;
            printf("%s: ",name[p]);
            while (!feof(giga))                   //using while loop until the end of file
            {
                fscanf(giga, "%s", line);                  
                int z = 0;
                for (int i = 0; i < strlen(line); i++) 
                {
                    if (isalpha(line[i]))          
                    {
                        str[z] = line[i];
                        z += 1;
                    }
                }
                str[z] = '\0';
                st=st+strlen(str);       //taking the length and storing that
                strcpy(bag[x], str);
                printf("%s ", bag[x]);
                x += 1;
            }
            z1=x;         //taking the no of words and storing into z1
            int len1 = st;
            fclose(giga);                  /*closing file operations */
            printf("\n%s: ",name[q]);
            giga = fopen(file[q],"r");    
            char line2[1000];
            char bag2[100][20];                //repeating the same for next file  
            x = 0;
            int st2=0;
            while (!feof(giga))              //here repeating unti end of file          
            {
                fscanf(giga, "%s", line2);
                int z = 0;
                for (int i = 0; i < strlen(line2); i++)  //checking for special characters until length of file
                {
                    if (isalpha(line2[i])) 
                    {
                        str[z] = line2[i];
                        z += 1;
                    }
                }
                str[z] = '\0';
                st2=st2+strlen(str);         //taking length of total file
                strcpy(bag2[x], str);
                printf("%s ", bag2[x]);
                x += 1;
            }
            z2=x;                      //making the count of words as variable z2
            int len2=st2,lcs=0,max_lcs=0;     //max lcs variable stores  longest sub string length
            fclose(giga);
            for(int i=0;i<z1;i++)
            {
                int k=i,lcs=0;            //using for loops to know longest sub string.
                int first=k;
                for(int j=0;j<z2;j++)
                {
                    if(strcmp(bag[k],bag2[j])==0)
                    {
                        lcs+=strlen(bag[k]);           //string compare using strcmp returns 0 if true
                        k+=1;                    //storing that into lcs variable
                    }
                    else
                    {
                        if(k>first)
                        {
                            break;          //exiting the loop using break condition
                        }
                    }
                }
                if(lcs>max_lcs)              
                {                                 //comparing lcs and  max lcs
                    max_lcs=lcs;       //bigger of this stored into maxlcs
                }
            }
             float match;              //taking match variable as result
            float a = max_lcs*2;
            float b=st+st2;
            // match = (a/b) * 100;        //result
            match=matc(a,b);      //calling that function included in header file
            plagarism[p][q]=match;     //storing match value into plagarism variable 
            plagarism[q][p]=match;
            printf("\nLcs method:::\nplagarism percentage : %.2f %%\n",plagarism[p][q]);
        }
    }
    printf("\nFile\t");               //this is used for displaying in file and matrix format 
    int y=0;                          
    for(int i=0;i<fcount;i++)     
    {
        printf("|%s\t",name[i] );     // '|'  used for displaying in better way 
        y+=strlen(name[i]);
        y+=4;                      //y variable for spacing 
    }
    printf("|");
    printf("\n");
    for(int j=0;j<y;j++)
    {
        printf("=");            //using '= '  for gap between file name & result and y used for spacing 

    }
    for(int i=0;i<fcount;i++)
    {
        printf("\n%s\t",name[i]);         //using for loop to display in matrix form
        for(int j=0;j<fcount;j++)           
        {
            printf("|%.2f\t",plagarism[i][j]);    //displaying the result stored in plagarism variable.
        }
        printf("|");                   //used for keeping the gap between results.
    }
    printf("\n");
    for(int j=0;j<y;j++)
    {
        printf("=");                        //using '=' for better outlook.

    }
}

