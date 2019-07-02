//
// Created by Administrator on 2019/7/2.
//

//
// Created by Administrator on 2019/7/2.
//

#include <stdio.h>
#include "io.h"
#include "../H/SystemInit.h"



int dirSearch(char *TonePath,char** fileName);

void toneListInit(char *TonePath, unsigned char *stateList[128][6] )
{
    char* fileName[128];
    dirSearch(TonePath,fileName);


//    printf( TonePath );
}

int dirSearch(char path[128],char** fileName )
{
//    char path[128] = TonePath;
    struct _finddata_t fa;
    long handle;
    unsigned m = 0;

    if((handle = _findfirst(strcat(path,"*"),&fa)) == -1L)
    {
        printf("The Path %s is wrong!\n",path);
        return 0;
    }
    printf("the content of this path is:\n");
    do
    {
        if( (fa.attrib==_A_ARCH||_A_HIDDEN||_A_RDONLY||_A_SUBDIR||_A_SYSTEM) && fa.name[0] != '.'  )
        {
            fileName[m] = fa.name;
            printf("%s\n",fa.name);
            m++ ;
        }

    }while(_findnext(handle,&fa) == 0); /* 成功找到时返回0*/

    _findclose(handle);

    return 0;

}