
//
// Created by Administrator on 2019/7/2.
//



#include <stdio.h>
#include "io.h"
#include "../H/SystemInit.h"
#include <string.h>


char fileName[64][256];
char * connect(char *s1, char *s2);
int dirSearch(char *path);



// 获取音色库的所有信息
void toneListInit(char *TonePath, unsigned char *stateList[128][6] )
{

    unsigned int size;
    int strLen=0;


    char *programPath = TonePath;
    char *programToneList;

    char *ToneListPath;
    char *ToneLibPath;



    printf("%s\n",TonePath);
    dirSearch(programPath);
    strLen = strlen(TonePath);
    programPath[strLen-1] = '\0';

    for(int i=0;i<64;i++)
    {
        if(fileName[i][0]=='\0') break;
        programToneList = connect(TonePath,fileName[i] );
        ToneListPath = connect(programToneList,"/" );
        ToneListPath = connect(ToneListPath,fileName[i] );
        ToneListPath = connect(ToneListPath,".toneLibList" ); // 获取音色库引导文件的路径
        ToneLibPath  = connect(ToneListPath,".toneLib" ); // 获取音色库文件

        //第一步 读取音色库的引导文件，获取音色库的信息
        


        printf("%s\n",ToneListPath );
        printf("%s\n",ToneLibPath );


    }
}


// 检索文件夹下所有的子文件夹和文件
int dirSearch(char *path )
{
    struct _finddata_t fa;
    long handle;
    unsigned int m=0,n = 0;

//    (handle = _findfirst(strcat(path,"*"),&fa));
    if((handle = _findfirst(strcat(path,"*"),&fa)) == -1L)
    {
        printf("The Path %s is wrong!\n",path);
        return 0;
    }
    do
    {
        if( (fa.attrib==_A_ARCH||_A_HIDDEN||_A_RDONLY||_A_SUBDIR||_A_SYSTEM) && fa.name[0] != '.'  )
        {
            while(fa.name[n] != *"")
            {
                fileName[m][n] = fa.name[n];
                n++;
            }
            m++;
            n = 0;
        }
    }
    while(_findnext(handle,&fa) == 0); /* 成功找到时返回0*/
    _findclose(handle);
    return 0;
}


//连接字符串
char * connect(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    if (result == NULL) exit (1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}


