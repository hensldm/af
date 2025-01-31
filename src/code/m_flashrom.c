#include "m_flashrom.h"
#include "global.h"

#include "libu64/gfxprint.h"

#include "m_common_data.h"
#include "m_cpak.h"
#include "m_lib.h"
#include "m_time.h"
#include "sFRm_flashrom.h"

extern s32 D_80106A90_jp;
extern s32 D_80106A94_jp;
extern u8 D_80106A98_jp;
extern s32 D_80106A9C_jp[6];

typedef UNK_RET (*D80106AB4Func)(UNK_PTR arg0, UNK_TYPE arg1, UNK_PTR arg2);
extern D80106AB4Func D_80106AB4_jp[2];

extern B8013A380Struct B_8013A380_jp;

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

u16 func_8008EEB4_jp(void* arg0, u32 size, u16 arg2) {
    return ~(func_8008EE7C_jp(arg0, size) - arg2) + 1;
}

s32 func_8008EEE8_jp(Save* save) {
    s32 ret = FALSE;

    if (save->unk_00004 == AF_GAME_CODE) {
        ret = TRUE;
    }
    return ret;
}

s32 func_8008EF0C_jp(Save* save, u16 landId) {
    s32 ret = FALSE;

    if (func_8008EEE8_jp(save)) {
        if (((save->unk_00008 & 0xFF00) == 0x3000) && (save->unk_00008 == landId)) {
            ret = TRUE;
        }
    }
    return ret;
}

s32 mFRm_CheckSaveData(void) {
    return func_8008EF0C_jp(&common_data.save, common_data.save.landInfo.id);
}

void mFRm_ClearSaveCheckData(Save* save) {
    save->unk_00004 = -1;
    save->unk_00008 = 0xFFFF;
    mem_copy((void*)&save->unk_00000A, (void*)&mTM_rtcTime_clear_code, sizeof(lbRTC_time_c));
    save->unk_000012 = 0;
}

void func_8008EFDC_jp(Save* save) {
    u16 landId = common_data.save.landInfo.id;

    save->unk_00004 = AF_GAME_CODE;
    save->unk_00008 = landId;
    lbRTC_TimeCopy(&save->unk_00000A, &common_data.time.rtcTime);
}

void func_8008F020_jp(B8013A380Struct* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = 0;
    arg0->unk_0C = NULL;
    arg0->unk_10 = NULL;
    arg0->unk_14 = 0;
}

UNK_RET func_8008F040_jp(UNK_PTR* arg0, UNK_TYPE arg1, B8013A380Struct* arg2) {
    u32 var_a1 = (arg1 == 0) ? 0 : 0x200;

    arg2->unk_00 = 1;
    arg2->unk_04 = var_a1;
    arg2->unk_08 = arg1;
    arg2->unk_0C = arg0;
    arg2->unk_10 = arg2->unk_0C;
    arg2->unk_14 = 0;

    sFRm_WriteAsync(arg2->unk_0C, arg2->unk_04, 0x80);
    return 0;
}

UNK_RET func_8008F0A0_jp(UNUSED UNK_PTR arg0, UNUSED UNK_TYPE arg1, B8013A380Struct* arg2) {
    u32 pageNum;
    s32 ret = 0;

    pageNum = arg2->unk_08 * 0x200;
    if (sFRm_IsBusy() == 1) {
        if (sFRm_GetResult() == -1) {
            if (arg2->unk_14 < 3) {
                arg2->unk_0C = arg2->unk_10;
                sFRm_WriteAsync(arg2->unk_0C, pageNum, 0x80);
                arg2->unk_14++;
                arg2->unk_04 = pageNum;
            } else {
                func_8008F020_jp(arg2);
                ret = -1;
                func_8008ECC8_jp(2);
            }
        } else {
            arg2->unk_04 += 0x80;
            if (arg2->unk_04 >= (pageNum + 0x200)) {
                sFRm_AwaitResult();
                func_8008F020_jp(arg2);
                ret = 1;
            } else {
                sFRm_AwaitResult();
                arg2->unk_0C = (u8*)arg2->unk_0C + 0x4000;
                sFRm_WriteAsync(arg2->unk_0C, arg2->unk_04, 0x80);
            }
        }
    }

    return ret;
}

UNK_RET func_8008F1BC_jp(UNK_PTR arg0, UNK_TYPE arg1) {
    UNK_RET ret = 1;

    if ((B_8013A380_jp.unk_00 >= 0) && (B_8013A380_jp.unk_00 < ARRAY_COUNT(D_80106AB4_jp))) {
        ret = D_80106AB4_jp[B_8013A380_jp.unk_00](arg0, arg1, &B_8013A380_jp);
    }

    return ret;
}

void func_8008F210_jp(void) {
    func_8008F020_jp(&B_8013A380_jp);
    D_80106A94_jp = 0;
}

s32 func_8008F23C_jp(void) {
    return D_80106A94_jp;
}

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
