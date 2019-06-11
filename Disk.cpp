#include "Disk.h"

#include<stdio.h>
#include<stdlib.h>



char* systemStartAddr;  //系统起始地址

void initSystem()
{
    systemStartAddr = (char*)malloc(system_size * sizeof(char));
    for(int i = 0; i < block_count; i++)
        systemStartAddr[i] = '0';
    int bitMapSize = block_count * sizeof(char) / block_szie;
    for(int i=0; i<bitMapSize; i++)
        systemStartAddr[i] = '1';  
}

void exitSystem()
{
    free(systemStartAddr);
}

int getBlock(int blockSize)
{
    int startBlock = 0;
    int sum = 0;
    for(int i = 0; i < block_count; i++)
    {
        if(systemStartAddr[i] == '0')
        {
            if(sum == 0)
                startBlock = i;
            sum++;
            if(sum == blockSize)
            {
                for(int j = startBlock; j < startBlock+blockSize; j++)
                    systemStartAddr[j] = '1';
                return startBlock;
            }

        }
        else
            sum = 0;
    }
    printf("not found such series memory Or memory is full\n");
    return -1;
}

char* getBlockAddr(int blockNum)
{
    return systemStartAddr + blockNum * block_szie; 
}

int getAddrBlock(char* addr)
{
    return (addr - systemStartAddr)/block_szie;
}

int releaseBlock(int blockNum, int blockSize)
{
    int endBlock = blockNum + blockSize;
    for(int i = blockNum; i < endBlock; i++)
        systemStartAddr[i] = '0';
    return 0;
}
