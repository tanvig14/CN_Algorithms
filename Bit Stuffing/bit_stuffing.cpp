#include<iostream>
using namespace std;

int freceiver(int data[],int flag[])
{
    int temp[8];
    for(int t=0; t<8; t++)
    {
        if(data[t] == flag[t])
            continue;
        
        else
            temp[t] = data[t];
    }
    int count = 8;
    cout<<"Data received: ";
    for(int q=count; q<16; q++)
    {
        if(data[q]==1 && data[q+1]==1 && data[q+2]==1 && data[q+3]==1 && data[q+4]==1)
        {    
            cout<<data[q]<<data[q+1]<<data[q+2]<<data[q+3]<<data[q+4];
            q = q+6;
        }
            
        else
            cout<<data[q];     
    }
    cout<<endl;
}

int main()
{
    int j, k, index = 0, count = 0, sender[8], receiver[50];
    int flag[8] = {0,1,1,1,1,1,1,0};    
    cout<<"Enter the data (8 bits)"<<endl;
    for(int i = 0; i < 8; i++)
    {
        cin>>sender[i];
    }
    
    for(j = 0; j<8; j++)
    {
        receiver[j] = flag[j];
        index++;
    }
        
    for(int m = 0; m < 8; m++)
    {
        if(sender[m] == 1)
            count++;
                 
        if(sender[m] == 0)
            count == 0;
                        
        if(count == 5)
        {    
            receiver[index] = 0;
            index++;
            count = 0;
        }     
        receiver[index] = sender[m];
        index++;
    }
    
    int c = 0, n = 0;        
    //cout<<"index: "<<index<<endl;    
    for(int mj = index; mj < (index+8) ; mj++)
    {
        receiver[mj] = flag[c];
        c++;
        n = mj;
    } 
        
    cout<<"Sent data after prefixing and suffixing with flag bits: ";
    for(int k1 = 0; k1 < n+1; k1++)
    {
        cout<<receiver[k1];
    }   
    cout<<endl;
    
    freceiver(receiver,flag);
}
