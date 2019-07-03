#include <stdio.h>
//#include "SynthesisLib/H/SystemInit.h"
#include "./SynthesisLib/H/SystemInit.h"

int main()
{
<<<<<<< HEAD
    char TonePath[128] = "G:/ToneLib1/";
=======
    char TonePath[128] = "D:/ToneLib1/";
>>>>>>> 5f6579119153c62f3a7b6e1c8fcaa81049ee6f8b
    unsigned char *stateList[128][6];

//    printf("hello world");
    toneListInit(TonePath,stateList);

//    toneListInit(TonePath,stateList);

    return 0;
}