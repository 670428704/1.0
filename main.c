#include <stdio.h>
//#include "SynthesisLib/H/SystemInit.h"
#include "./SynthesisLib/H/SystemInit.h"


int main()
{

    char TonePath[256] = "G:/ToneLib1/";
    unsigned char *stateList[128][6];

    toneListInit(TonePath,stateList);


    return 0;
}