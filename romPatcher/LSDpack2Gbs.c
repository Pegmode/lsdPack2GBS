#include "LSDpack2Gbs.h"

//uint8_t


void write16Bit(uint8_t* dest,int val){//little endian
    dest[0] = (uint8_t)val&0xFF;
    dest[1] = (uint8_t)(val>>8)&0xFF;
}

int main(int argc, char const *argv[])
{   
    uint8_t* gbRom;
    uint8_t* gbsFile;
    long int romSize;
    char* filepath = "gbsRom.gb";
    char* outpath = "test.gbs";
    FILE* fi = fopen(filepath,"rb");
    fseek(fi,0,SEEK_END);
    romSize = ftell(fi);
    gbRom = (uint8_t*)malloc(romSize);
    gbsFile = (uint8_t*)calloc(romSize+0x400,1);
    fseek(fi, 0, SEEK_SET);
    fread(gbRom,1,romSize,fi);
    fclose(fi);

    if(memcmp(&gbRom[ROMCHECKADDRESS],"pegLsdj",7) != 0){
        printf("ROM is not correct type. Export to the custom LSDpack2Gbs Game Boy ROM.\n");
        exit(0);
    }

    memcpy(&gbsFile[0],"GBS",3);//Identifier
    gbsFile[3] = 1;
    gbsFile[4] = 1;//NUMBER OF SONGS
    gbsFile[5] = 1;//First song
    //load Address
    write16Bit(&gbsFile[0x6],0x470);
    //init address
    write16Bit(&gbsFile[0x8],0x490);
    //play address
    write16Bit(&gbsFile[0xA],0x4B1);
    //SP init
    write16Bit(&gbsFile[0xC],0xFFFE);
    //timer modulo(rTMA)
    gbsFile[0xE] = ENGINETMA;//0x4a
    //timer control(rTAC)
    gbsFile[0xF] = ENGINETAC;//6;
    //Title
    //Author
    //Copyright
    
    //code+Data
    memcpy(&gbsFile[0x70],&gbRom[0x470],romSize-0x470);

    FILE* fo = fopen(outpath,"wb");
    fwrite(gbsFile,1,romSize,fo);
    fclose(fo);



    printf("%c\n",gbsFile[0]);
    free(gbRom);
    free(gbsFile);
    return 0;
}

//s