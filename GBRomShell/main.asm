SECTION	"Timer interrupt",ROM0[$50]
    jp TIMAIRQ
SECTION "boot",ROM0[$100]
    jp  Init
SECTION	"MBC type",ROM0[$147]
    db $19;CART_MBC5
SECTION	"Cart Size",ROM0[$148]
    db  $54; 96 banks (1.5 MB)
SECTION "code",ROM0[$150]
check1:
    db "pegLsdj"
SECTION "init",ROM0[$400];offset for .gbs
Init:
	ld a,0
	call LsdjPlaySong
    ld a,%00000000
	ld [$FF41],a;rSTAT
	ld a,%11010011
    ld [$FF40],a;rLCDC
	ld a,%00000100
	ld [$FFFF],a;rIE
    ld a,%110
    ld [$FF07],a;rTac
    ld a,$4a
    ld [$FF06],a;rTMA
	ei
Main:
	nop
	xor a
.l1
	inc a
	jr nz,.l1

	jp Main
TIMAIRQ:
    call LsdjTick
    reti

;$430 is next section

include "player.s"
include "songs.s" ;Demo Song "Maniac" by INFU
;include "testsb.s"
