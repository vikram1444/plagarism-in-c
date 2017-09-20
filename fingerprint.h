float fingerprint(char s1[],char s2[],int n) //this function returns the manipulated result.
{                                           //getting arguments string 1, string 2 ,number
	char str1[strlen(s1)];   //knowing the strlen of file 1 and allocating size according to it
	int i,j,length1=0;                        
	int num=10007;
	for (i=0;i<strlen(s1);i++) 
	{
		if (96<s1[i]&&s1[i]<123)    //knowing whether it is text or it is alphanumeric.
		{
			str1[length1]=s1[i]; //here storing the s1 words in array str1
			length1++;
		}
	}
	int values1[100]={0};
	int k1=0,flag=0;
	for(i=0;i<length1+1-n;i++) //taking that until n we have given
	{
		int count1=0;
		for(j=n-1;j>-1;j--)
		{
			count1+=((int)str1[i])*(pow(10,j)); //multiplying respective ascii value of word with power of 10 
			i++;                              //adding respective value to count1
		}
		i=i-n;
		count1=count1%num;    //dividing the count1 with number that you are considered as bigger.
		values1[i]=count1;   //storing that value in values1 array .
		k1++;            //k1 is count of no of numbers
	}
	char str2[strlen(s2)];   //knowing the strlen of file 2 and allocating size according to it 
	int length2=0;
	for (i=0;i<strlen(s2);i++) //using for loop until string length
	{
  		if (96<s2[i]&&s2[i]<123) //knowing whether it is text or it is alphanumeric.
		{
			str2[length2]=s2[i]; //storing the word in str2
			length2++;          
		}
	}
	int values2[100]={0};
	int k2=0;
	flag=0;
	for(i=0;i<length2+1-n;i++) //taking that until n we have given
	{
		int count2=0;
		for(j=n-1;j>-1;j--)
		{	
			count2+=((int)str2[i])*(pow(10,j)); //multiplying respective ascii value of word with power of 10
			i++;                         //adding respective value to count2
		}
		i=i-n;
		count2=count2%num;   //dividing the count2 with number that you are considered as bigger.
		values2[i]=count2; //storing that number in array values2.
		k2++;         //k2 is count of no of numbers
		flag=0;
	}
	int count=0;
	for (i=0;i<k1;i++)
	{
		for (j=0;j<k2;j++)
		{
			if (values1[i]==values2[j]) //if a number in array values1 is equal to values2 we are increasing count
			{
				count++;
				break; 
			}
		}
	}
	float percentage=((count*2.0)/(k1+k2))*100; //result is indented by this formula 
	return percentage;        //we are returning the percentage.
}