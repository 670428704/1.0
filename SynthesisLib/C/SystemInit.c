//
// Created by Administrator on 2019/7/2.
//

//
// Created by Administrator on 2019/7/2.
//

#include <stdio.h>
#include "io.h"
#include "../H/SystemInit.h"
#include <string.h>


char fileName[64][256];
char * dirSearch(char *TonePath);


// 获取音色库的所有信息
void toneListInit(char *TonePath, unsigned char *stateList[128][6] )
{
    unsigned int size;
    dirSearch(TonePath);
    for(int i=0;i<30;i++)
    {
        printf("%s\n", fileName[i] );
    }
}




// 检索文件夹下所有的子文件夹和文件
char * dirSearch(char path[128] )
{
    struct _finddata_t fa;
    long handle;
    unsigned int m=0,n = 0;

    if((handle = _findfirst(strcat(path,"*"),&fa)) == -1L)
    {
        printf("The Path %s is wrong!\n",path);
        return 0;
    }
    do
    {
        if( (fa.attrib==_A_ARCH||_A_HIDDEN||_A_RDONLY||_A_SUBDIR||_A_SYSTEM) && fa.name[0] != '.'  )
        {
            while(fa.name[n] != *"") {
                fileName[m][n] = fa.name[n];
                n++;
            }
            m++;
            n =0;
        }
    }
    while(_findnext(handle,&fa) == 0); /* 成功找到时返回0*/
    _findclose(handle);
    return 0;
}