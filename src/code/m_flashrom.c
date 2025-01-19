#include "m_flashrom.h"
#include "global.h"

#include "libu64/gfxprint.h"

#include "sFRm_flashrom.h"

extern s32 D_80106A90_jp;
extern s32 D_80106A94_jp;
extern u8 D_80106A98_jp;
extern s32 D_80106A9C_jp[6];

void func_8008ECA0_jp(void) {
    bzero(&D_80106A9C_jp, sizeof(D_80106A9C_jp));
}

void func_8008ECC8_jp(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < ARRAY_COUNT(D_80106A9C_jp))) {
        D_80106A9C_jp[arg0] = TRUE;
    }
}

void func_8008ECF0_jp(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < ARRAY_COUNT(D_80106A9C_jp))) {
        D_80106A9C_jp[arg0] = FALSE;
    }
}

void func_8008ED14_jp(gfxprint* printer) {
    gfxprint_color(printer, 250, 100, 250, 255);
    gfxprint_locate8x8(printer, 22, 3);

    if (D_80106A9C_jp[0]) {
        gfxprint_printf(printer, "N");
    }

    if (D_80106A9C_jp[1]) {
        gfxprint_printf(printer, "A");
    }

    if (D_80106A9C_jp[2]) {
        gfxprint_printf(printer, "W");
    }

    if (D_80106A9C_jp[3]) {
        gfxprint_printf(printer, "R");
    }

    if (D_80106A9C_jp[4]) {
        gfxprint_printf(printer, "C");
    }

    if (D_80106A9C_jp[5]) {
        gfxprint_printf(printer, "O");
    }
}

void func_8008EE24_jp(void) {
    sFRm_Init();
    func_8008FA50_jp();
    D_80106A90_jp = 0;
    D_80106A94_jp = 0;
}

s32 func_8008EE5C_jp(void) {
    return D_80106A90_jp;
}

u8 func_8008EE6C_jp(void) {
    return D_80106A98_jp;
}

u16 func_8008EE7C_jp(u16* arg0, u32 size) {
    u16 ret = 0;

    if ((size % 2) == 0) {
        for (; size > 0; size -= 2) {
            ret += *arg0;
            arg0++;
        }
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008EEB4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008EEE8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008EF0C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/mFRm_CheckSaveData.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/mFRm_ClearSaveCheckData.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008EFDC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F020_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F040_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F0A0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F1BC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F210_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F23C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F24C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F530_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F5FC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F648_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F768_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F7C8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F8A0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F938_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008F968_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FA28_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FA50_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FA74_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FAB4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FAE0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FB64_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FBEC_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FCE8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FDD4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FE74_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_8008FF60_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_80090044_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_flashrom/func_800900B0_jp.s")
