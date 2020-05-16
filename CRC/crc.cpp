#include <iostream>
using namespace std;
int currpos;
int *process(int [],int []);
int extract(int []);
int *exdata(int [],int ); 
int *appendres(int [],int [],int );
int *XOR(int [],int []);

int *process(int data[],int crcg[])
{
    int ct,d,d1,d2,d3,d4,dr,dr1,v,v1,t,pd,pl,var,va,mva,mycount,index = 0,rarray[4],darr[4],result[4],fresult1[4];  
    static int fresult[4], re[4];
    int *newresult, *myarr, *presult, *pr = result;
    currpos = 4;
    t = 0;
    
    for(var=0; var<4; var++)                 
    {
        fresult[var] = data [var];
    }
    
    while(t != 1)       
    {
        presult = XOR(fresult,crcg);
    
        for(d2=0; d2<4; d2++)      
        {
            result[d2] = *(presult + d2);
        }
        
        mycount = extract(result);        
        index = 0;
       
        for(mva=mycount; mva<4; mva++)      
        {
               rarray[index] = result[mva];
               index++;
        }
          
        myarr = exdata(data,mycount);         
        for(d1=0; d1<4; d1++)                
        {
            darr[d1] = *(myarr + d1);
        }
    
        if(myarr[0] == -2)
        {
            for(pl = 0; pl<4; pl++)
            {
                re[pl] = 0;
            }
            return re;
        }
        newresult = appendres(rarray,darr,mycount);           
        for(d4=0; d4<4; d4++)                                 
        {
            fresult[d4] = *(newresult + d4);
        }
        
        for(pd=0; pd<4; pd++)                 
        {
            if(fresult[pd] == -1)
            {    
                t = 1;
                break;
            }
        }
    }
    cout<<"Final XOR result: ";
    ct = 0;
    for(dr = 0; dr < 4; dr++)
    {
        if(fresult[dr] == 0 || fresult[dr] == 1)
            ct++;
                
        fresult1[dr] = fresult[dr];
    }
    v = 3-ct;               
    for(dr1 = 0; dr1 < v; dr1++)
    {
        fresult[dr1] = 0;
    }
    v1 = 0;
    for(v; v < 3; v++)
    {
        if(fresult1[v1] != -1)
        {
            fresult[v] = fresult1[v1];
            v1++;
        }
        else
            break;
    }
    
    for(d=0; d<4; d++)                                            
    {
        if(fresult[d] == -1)
            break;
            
        else
            cout<<fresult[d];
    }
    cout<<endl;
    return fresult;
}

int *XOR(int d[], int c[])
{
    static int res[4];   
    for(int mv=0; mv<4; mv++)    
    {
        if((d[mv] == 1 && c[mv] == 1) || (d[mv] == 0 && c[mv] == 0))
            res[mv] = 0;
            
        else
            res[mv] = 1;
    }
    return res;
}

int extract(int ex[])      
{
    int count = 0;
    for(int v1=0; v1<4; v1++)
    {
        if(ex[v1] == 0)
            count++;
            
        else if(ex[v1] == 1)
            break;
    }   
    
    if(ex[0] == 0 && ex[1] == 0 && ex[2] == 0 && ex[3] == 0)
    {
        count = -1;
        return count;
    }
    else    
        return count;
}

int *exdata(int data[],int mycount)
{
    static int arr[4];
    int q1 = 0;
    if(mycount == -1)
    {
        int tp = currpos;
        for(int q = tp; q<(tp+4); q++)
        {
            if(currpos > 9)
            {
                arr[0] = -2;
                return arr;
            }
                
            else
            {
                arr[q1] = data[q];
                q1++;
                currpos++;
            }
        }
        return arr;
    }
    
    else
    {
        int temp;
        for(int q=currpos; q<(currpos + mycount); q++)
        {
            if((currpos+mycount) > 10)
            { 
                temp = 10-currpos;
                break;
            }
                
            else
            {
                arr[q1] = data[q];
                q1++;
                temp = q1;
            }
        }

        for(int mq=temp; mq<4; mq++)
        {
            arr[mq] = -1;
        }
        currpos = currpos + mycount;
        return arr;
    }
}

int *appendres(int result[],int data[],int counter)
{
    static int r[4];
    int z;
    if(counter == -1)
    {
        for(int y = 0; y<4; y++)
        {
            r[y] = data[y];
        }
    return r;
    }
    
    else
    {
        for(int w = 0; w<(4-counter);w++)
        {
            r[w] = result[w];
            z = w;
        }
    
        z++;
        
        for(int y = 0; y<counter; y++)
        {
            r[z] = data[y];
            z++;
        }
        return r;
    }
}

int main()
{
    int i, i1, j, m, mn, d, dm, p, p1, in=7, data[10], crcg[4], crcb[3], error[3], *temp, *temp1;
    cout<<"Enter the data"<<endl;
    for(i = 0; i < 7; i++)
    {
        cin>>data[i];
    }
    
    for(i1 = 7; i1 < 10; i1++)
    {
        data[i1] = 0;
    }
    
    cout<<"Enter the CRC-G"<<endl;
    for(j = 0; j < 4; j++)
    {
        cin>>crcg[j];
    }
   
    temp = process(data,crcg);
    for(d = 0; d < 3; d++)        
    {
        crcb[d] = *(temp + d);
    }
    
    for(p = 0; p < 3; p++)
    {
        data[in] = crcb[p];
        in++;
    }
    
    cout<<"Data sent to receiver: ";
    for(p1 = 0; p1 < 10; p1++)
    {
        cout<<data[p1];
    }
    cout<<endl;
    
    temp1 = process(data,crcg);
    for(dm = 0; dm < 3; dm++)              
    {
        error[dm] = *(temp1 + dm);
    }
    
    cout<<"Error bits: ";
    for(mn = 0; mn < 3; mn++)                   
    {
         cout<<error[mn];
    }
    cout<<endl;
}
