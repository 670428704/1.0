#include <stdio.h>
//#include "SynthesisLib/H/SystemInit.h"
#include "./SynthesisLib/H/SystemInit.h"

int main()
{
    char TonePath[128] = "G:/ToneLib1/";
    unsigned char *stateList[128][6];

//    printf("hello world");
    toneListInit(TonePath,stateList);

//    toneListInit(TonePath,stateList);

    return 0;
}