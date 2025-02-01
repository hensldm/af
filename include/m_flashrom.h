#ifndef M_FLASHROM_H
#define M_FLASHROM_H

#include "ultra64.h"
#include "unk.h"

struct gfxprint;
struct Save;

typedef struct B8013A380Struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ void* unk_10;
    /* 0x14 */ s32 unk_14;
} B8013A380Struct; // size >= 0x18

void func_8008ED14_jp(struct gfxprint* printer);
void func_8008EE24_jp(void);
u16 func_8008EE7C_jp(u16* arg0, u32 size);
u16 func_8008EEB4_jp(void* arg0, u32 size, u16 arg2);
s32 func_8008EEE8_jp(struct Save* save);
s32 mFRm_CheckSaveData(void);
void mFRm_ClearSaveCheckData(struct Save* save);
void func_8008EFDC_jp(struct Save* save);
s32 func_8008F1BC_jp(UNK_PTR arg0, UNK_TYPE arg1);
void func_8008F210_jp(void);
s32 func_8008F23C_jp(void);
s32 func_8008F768_jp(UNK_PTR arg0, UNK_PTR arg1);
s32 func_8008F7C8_jp(void);
s32 func_8008F8A0_jp(UNK_PTR arg0, s32 arg1);
// void func_8008F938_jp();
// void func_8008F968_jp();
// void func_8008FA28_jp();
void func_8008FA50_jp(void);
// void func_8008FA74_jp();
// void func_8008FAB4_jp();
// void func_8008FAE0_jp();
// void func_8008FB64_jp();
// void func_8008FBEC_jp();
// void func_8008FCE8_jp();
// void func_8008FDD4_jp();
// void func_8008FE74_jp();
// void func_8008FF60_jp();
s32 func_80090044_jp(void);
// void func_800900B0_jp();

#endif
