#include<iostream>
using namespace std;

int pass = 0;
int *checksum(int a[], int b[])
{   
    static int mysum[8]; 
    int carry = 0, i, carray[8];
    
    for(i = 7; i >= 0; i--)
    {
        if(a[i] == 0 && b[i] == 0 && carry == 0)
        {
            mysum[i] = 0;
            carry = 0;
        }
        else if(a[i] == 0 && b[i] == 0 && carry == 1)
        {
            mysum[i] = 1;
            carry = 0;
        }
        else if(a[i] == 0 && b[i] == 1 && carry == 0)
        {
            mysum[i] = 1;
            carry = 0;
        }
        else if(a[i] == 0 && b[i] == 1 && carry == 1)
        {
            mysum[i] = 0;
            carry=1;
        }
        else if(a[i] == 1 && b[i] == 0 && carry == 0)
        {
            mysum[i] = 1;
            carry = 0; 
        }
        else if(a[i]==1 && b[i]==0 && carry==1)
        {
            mysum[i]=0;
            carry=1;
        }
        else if(a[i]==1 && b[i]==1 && carry==0)
        {
            mysum[i]=0;
            carry=1;
        }
        else if(a[i]==1 && b[i]==1 && carry==1)
        {
            mysum[i]=1;
            carry=1;
        }
        else
            break;
    }
  
    if(carry == 1)
    {
        int *ptr;
        for(int y = 0; y<8; y++)
        {
            carray[y] = 0;
        }
        carray[7] = carry;
        ptr = checksum(mysum,carray);
        for(int q = 0; q < 8; q++)              
        {
            mysum[q] = *(ptr + q);
        }
    }
    return mysum;
}

int main()
{
    int i, counter = 0;
    int k1[8], k2[8], k3[8], k4[8], result1[8], result2[4], sum[8], complement[8], verify[8], *tk3, *tk4, *tfinal, *ptrverify;
    cout<<"Enter the input data (4 streams of 8 bits each)"<<endl;
    
    for(int q = 0; q<8; q++)
    {
        cin>>k1[q];
    }
    
    for(int q1 = 0; q1<8; q1++)
    {
        cin>>k2[q1];
    }
    
    for(int q2 = 0; q2<8; q2++)
    {
        cin>>k3[q2];
    }
    
    for(int q3 = 0; q3<8; q3++)
    {
        cin>>k4[q3];
    }
    
    cout<<"\nSENDER:"<<endl;
    tk3 = checksum(k1,k2);
    for(int dm = 0; dm < 8; dm++)              
    {
        result1[dm] = *(tk3 + dm);
    }
    
    tk4 = checksum(result1,k3);
    for(int d = 0; d < 8; d++)              
    {
        result2[d] = *(tk4 + d);
    }
    
    tfinal = checksum(result2,k4);
    for(int d1 = 0; d1 < 8; d1++)              
    {
        sum[d1] = *(tfinal + d1);
    }
    
    cout<<"Sum"<<endl;
    for(int q1=0;q1<8;q1++)
    {
        cout<<sum[q1];
    }
    cout<<"\n\n";
       
    for(i=0;i<8;i++)
    {
        if(sum[i]==0)
            complement[i]=1;
        else
            complement[i]=0;
    }
      
    cout<<"Checksum"<<endl;
    for(int r1=0;r1<8;r1++)
    {
       cout<<complement[r1];
    }
    cout<<"\n\n";
   
   
    cout<<"\n\nRECEIVER:"<<endl;
    ptrverify = checksum(sum,complement);
    
    for(int o = 0; o < 8; o++)              
    {
        verify[o] = *(ptrverify + o);
    }
    
    cout<<"Sum + Complement"<<endl;
    for(int hi = 0; hi < 8; hi++)
    {
        cout<<verify[hi];
        if(verify[hi] == 0)
            counter++;
    }
    cout<<"\n\n";
    
    cout<<"Complement of final sum"<<endl;
    for(i=0;i<8;i++)
    {
        if(verify[i]==0)
            complement[i]=1;
        else
        {
            complement[i]=0;
            counter++;
        }
        cout<<complement[i];
    }
    cout<<"\n\n";
    
    if(counter == 8)
        cout<<"Data received correctly!\n"<<endl;
    
    else
        cout<<"Error"<<endl;
}
