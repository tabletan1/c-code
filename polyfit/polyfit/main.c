//
//  main.c
//  polyfit
//
//  Created by Rencheng Tan on 7/5/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
bool Matrix_PolyFit(double *x,double *y,int X_Y_Number,int Fit_N,double *ks)
{
    /*
     对X_Y_Number组数据x,y进行Fit_N次多项式拟合,拟合返回多项式的系数ks
     x[X_Y_Number],y[X_Y_Number],ks[Fit_N+1]
     */
    if (Fit_N>X_Y_Number || X_Y_Number<1)
    {
        return false;
    }
    int i,j,index,n;
    double temp,*x2,*y2;
    Fit_N++;
    y2=new double[Fit_N];
    x2=new double[Fit_N*Fit_N];
    for (i=0,index=0;i<Fit_N;i++)
    {
        y2[i]=0;
        for (j=0;j<Fit_N;j++)
        {
            x2[index+j]=0;
        }
        index+=Fit_N;
    }
    x2[0]=X_Y_Number;
for(i=0;i<Fit_N;i++)
{
    for (j=i+1;j<Fit_N;j++)
    {
        temp=0;
        n=i+j;
        for (index=0;index<X_Y_Number;index++)
        {
            temp+=pow(x[index],n);
        }
        index=j;
        for (n=i;n<Fit_N;n++)
        {
            if (index>=0)
            {
                x2[n*Fit_N+index]=temp;
            }
            index--;
        }
    }
}
    n=Fit_N+Fit_N-2;
    temp=0;
    for (i=0;i<X_Y_Number;i++)
    {
        temp+=pow(x[i],n);
    }
    x2[Fit_N*Fit_N-1]=temp;
    for (i=0;i<Fit_N;i++)
    {
        temp=0;
        for (j=0;j<X_Y_Number;j++)
        {
            temp+=y[j]*pow(x[j],i);
        }
        y2[i]=temp;
    }if (Matrix_Solve(x2,y2,Fit_N,Fit_N,ks))
    {
        delete []y2;
        delete []x2;
        return true;
    }
    else
    {
        delete []y2;
        delete []x2;
        return false;
    }
}
