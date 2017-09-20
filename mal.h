double euclidean(int w1[],int l1)
{
    int mul,sum=0;                        //here using euclidean function to get euclidean norm
    double power;
    for (int i = 0; i < l1; i++) {
        mul=w1[i]*w1[i];
        sum=sum+mul;                     //doing sum of total
    }
    power=sqrt(sum);                //using sqrt to get euclidean norm
    return power;
}
double dot(int ar1[],int ar2[],char w1[100][100],char w2[100][100],int l1,int l2)
{                       //dot function for getting dot product  
    double sum=0;
    int mul;                              
    for (int i = 0; i <l1 ; i++)       //using for loops to compare respective dot for getting respective dot product
    {
        for (int j = 0; j <l2 ; j++)
        {
            if(strcmp(w1[i],w2[j])==0)  //comparing using strcmp default function so that it returns 0 if equal
            {
                mul=ar1[i]*ar2[j];
                sum=sum+mul;
            }
        }

    }
    return sum;          //returning dot product
}