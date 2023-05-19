#include<stdio.h>
void main()
{
    int data[100],ch,sentData[100],idealData[100],par,i,flag=0;
    do
    {
        printf("\nEnter 1 for even 0 for odd parity ");
        scanf("%d",&par);
        printf("\n1)Transmission\n2)Reception\n3)Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter 4 bits of data ");
            for(i=0;i<4;i++)
            scanf("%d",&sentData[i]);
            data[3]=sentData[3];
            data[5]=sentData[2];
            data[6]=sentData[1];
            data[7]=sentData[0];
            if(par==1)
            {
                data[1]=data[3]^data[5]^data[7];
                data[2]=data[3]^data[6]^data[7];
                data[4]=data[5]^data[6]^data[7];
            }
            else
            {
                data[1]=1-(data[3]^data[5]^data[7]);
                data[2]=1-(data[3]^data[6]^data[7]);
                data[4]=1-(data[5]^data[6]^data[7]);
            }
            for(i=7;i>0;i--)
            printf("%d",data[i]);
        }
        if(ch==2)
        {
            printf("Enter seven bit data ");
            for(i=7;i>0;i--)
            scanf("%d",&data[i]);
            if(par==1)
            {
                idealData[1] = data[3]^data[5]^data[7]^data[1];
                idealData[2] = data[3]^data[6]^data[7]^data[2];
                idealData[4] = data[5]^data[6]^data[7]^data[4];
            }
            else
            {
                idealData[1]=1-(data[3]^data[5]^data[7]^data[1]);
                idealData[2]=1-(data[3]^data[6]^data[7]^data[2]);
                idealData[4]=1-(data[5]^data[6]^data[7]^data[4]);
            }
            int e = 4*idealData[4] + 2*idealData[2] + 1*idealData[1];
            // printf("%d",e);
            if(e==0)
            printf("No errors ");
            else
            {
                data[e] = 1-data[e];
                printf("Correct hamming code is ");
                for(i=7;i>0;i--)
                printf("%d",data[i]);
            }
        }
    }while(ch!=3);
}