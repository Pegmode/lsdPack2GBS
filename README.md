# lsdPack2GBS
Project to write a .gbs converter for LSDJ. Currently investigating if this is possible. Currently there are issues with players playing back the exported .gbs. **Currently exports a usable .gbs but there are issues.**

## build
warning: this is in a very rough experimental state

1. use [lsdpack](https://github.com/jkotlinski/lsdpack) to generate song data. 
2. edit `SECTION "SONG_LOCATIONS",ROM0` in the exported .s file to `SECTION "SONG_LOCATIONS",ROM0[$470]`
3. rename the exported .s file to `songs.s`
4. build the ROM in `/GBRomShell` using RGBDS
5. build the romPatcher using make (windows only)
6. rename the compiled ROM to `gbsRom.gb`
7. run `LSDpack2Gbs.exe` with `gbsRom.gb` in the same directory

## requirements 
- MinGW make (windows)
- MinGW gcc (must be added to PATH) (windows)
- [RGBDS](https://github.com/gbdev/rgbds) 
- [lsdpack](https://github.com/jkotlinski/lsdpack)

## current state and issues
I have changed the update method from LYC to the timer interupt so that it can work with the [.gbs specs](https://ocremix.org/info/GBS_Format_Specification). Currently the ROM works fine but the exported .gbs does not. I have noticed that if you remove the cart type in the header and run the rom in bgb, the problem behavoir will arise. This is the same for standard non modified lsdpack. I personally suspect there is some issue with the way the engine changes ROM banks. Others have said it may be due to the changed timing method. I had my doubts because:
1. The issue can be replicated in the unmodified player 
2. The timing works fine in my modified stand alone ROM.

Progress is stalled untill this can be rectified. 

## credits
uses [lsdpack](https://github.com/jkotlinski/lsdpack) player

thanks to Defense Mechanism and DevEd. Big thanks to Infu for his demo LSDJ song which is included.
