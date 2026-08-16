// 6005d1e4  thermal__6005d1e4  size=190 bytes
// src: thermal.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   600d4308 FUN_600d4308
//   6013cf40 thunk_EXT_FUN_00007d10
//   6004cb14 FUN_6004cb14
//   6010165c FUN_6010165c
//   6013d3d8 thunk_EXT_FUN_0000b4c2


/* src: thermal.cc */

uint thermal__6005d1e4(int param_1,uint3 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    uVar3 = 3;
  }
  else {
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(DAT_6005d2a4);
      bVar7 = *DAT_6005d2a4 == '\0';
      if (!bVar7) goto LAB_6005d216;
      bVar7 = (bool)hasExclusiveAccess(DAT_6005d2a4);
    } while (!bVar7);
    *DAT_6005d2a4 = '\x01';
    bVar7 = true;
LAB_6005d216:
    DataMemoryBarrier(0x1b);
    uVar3 = 0;
    if (bVar7) {
      if (*(int *)(param_1 + 0x188) == 5) {
        FUN_6010165c(0x14,DAT_6005d2ac,0x10a,DAT_6005d2a8,param_1,(uint)param_2);
        uVar3 = FUN_600d4308(*(undefined4 *)(DAT_6005d2b0 + 4));
        if ((uVar3 & 0xff) != 0) {
          return uVar3;
        }
      }
      thunk_EXT_FUN_0000b4c2(param_1);
      uVar1 = DAT_6005d2b4;
      iVar5 = *(int *)(param_1 + 0x54);
      if (iVar5 == 10) {
        uVar3 = 8;
      }
      else {
        for (iVar6 = 0; uVar2 = DAT_6005d2b8, iVar5 != iVar6; iVar6 = iVar6 + 1) {
          iVar4 = FUN_6004cb14(*(undefined4 *)(iVar6 * 0xc + param_1 + 0x58),uVar1);
          if (iVar4 == 0) {
            uVar3 = 6;
            goto LAB_6005d290;
          }
        }
        iVar6 = iVar5 * 0xc + 4;
        *(undefined4 *)(param_1 + iVar5 * 0xc + 0x58) = DAT_6005d2b4;
        *(undefined4 *)(param_1 + 0x58 + iVar6) = uVar2;
        uVar3 = 0;
        *(undefined4 *)(param_1 + 0x58 + iVar6 + 4) = DAT_6005d2bc;
        *(int *)(param_1 + 0x54) = iVar5 + 1;
      }
LAB_6005d290:
      thunk_EXT_FUN_00007d10(param_1);
    }
  }
  return uVar3;
}


