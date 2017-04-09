//
//  main.c
//  p1
//
//  Created by Rencheng Tan on 7/3/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
    char result[900];
    int  rowi;
    int  coli;
    char cha[5];
    char StrLine[1024];
    for(int i = 0; i < 900; i++)
        result[i] = '.';

    FILE *fp = fopen("/Users/tabletan/Desktop/hw2-data2.txt", "r");
    
    while(!feof(fp))
    {
        fscanf(fp,"%d%d%s",&rowi,&coli,&cha);
        fgets(StrLine,1024,fp);
        char c = cha[1];
        if(rowi > 30 || rowi < 0 || coli > 30 || coli < 0)
        {
            printf("exceed the range");
            exit(1);
        }
        if(rowi == 0 || coli == 0)
            break;
        else
        {
            int index = (coli-1)*30+rowi-1;
            result[index] = c;
        }
    }
    for(int i = 0; i < 30; i ++)
    {
        for(int j = 0; j < 30; j++)
            printf("%c", result[i*30+j]);
        printf("\n");
    }
}
