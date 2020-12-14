#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

//GB ROM ADDRESSES
int ROMCHECKADDRESS = 0x150;
//int TMASETADDRESS = 0x16C;//modulo
//int TACSETADDRESS = 0x169;//control
int ENGINETMA = 0x4a;//def 4a
int ENGINETAC = 6;