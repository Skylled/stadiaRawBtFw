// 60068024  mimxrt10xx_flash_memory__60068024  size=320 bytes
// src: mimxrt10xx_flash_memory.cc
// --- callers ---
// --- callees ---
//   60101b76 FUN_60101b76
//   600d4752 FUN_600d4752
//   600d803e FUN_600d803e
//   60067e8c flash_memory__60067e8c
//   60101740 FUN_60101740
//   600d80d0 FUN_600d80d0
//   60067f20 FUN_60067f20


/* src: mimxrt10xx_flash_memory.cc */

char mimxrt10xx_flash_memory__60068024(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined1 **ppuVar12;
  int aiStack_d8 [4];
  int *local_c8;
  uint local_c4;
  undefined1 *local_c0 [4];
  int iStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [134];
  
  uVar5 = (uint)*(byte *)(param_1 + 0x18);
  if ((param_2 == uVar5 * (param_2 / uVar5)) &&
     (iVar8 = param_4 - uVar5 * (param_4 / uVar5), iVar8 == 0)) {
    local_c4 = param_4;
    if (uVar5 != 0x10) {
      local_c0[0] = DAT_60068164;
      local_ac = 0;
      local_c0[1] = (undefined1 *)0x60;
      local_c0[2] = local_aa;
      local_ab = 0;
      local_aa[0] = 0;
      local_c0[3] = (undefined1 *)0x80;
      iStack_b0 = iVar8;
      FUN_60101b76(local_c0 + 2,DAT_60068168);
      FUN_60101740(local_c0);
    }
    iVar8 = -(*(byte *)(param_1 + 0x18) + 7 & 0x1f8);
    iVar3 = FUN_600d4752(param_1,param_2);
    iVar11 = (int)&local_c8 + iVar8;
    FUN_60067f20(local_c0);
    for (; local_c4 != 0; local_c4 = local_c4 - uVar5) {
      piVar9 = *(int **)(param_1 + 0x14);
      FUN_600d80d0(local_c0 + 3,iVar3);
      iVar4 = param_3;
      if (*(int *)(param_1 + 0x24) == 1) {
        iVar10 = 0;
        do {
          *(byte *)(iVar11 + iVar10) =
               *(byte *)(param_3 + iVar10) ^ *(byte *)((int)local_c0 + iVar10);
          iVar10 = iVar10 + 1;
          iVar4 = iVar11;
        } while (iVar10 != 0x10);
      }
      iVar6 = *(int *)(param_1 + 0x20);
      iVar10 = *piVar9;
      *(int *)((int)aiStack_d8 + iVar8 + 8) = iVar6;
      uVar7 = *(undefined4 *)(param_1 + 0x1c);
      ppuVar12 = local_c0;
      if (iVar6 != 2) {
        ppuVar12 = (undefined1 **)0x0;
      }
      uVar1 = *(undefined1 *)(param_1 + 0x18);
      *(undefined1 ***)((int)aiStack_d8 + iVar8) = ppuVar12;
      *(undefined4 *)((int)aiStack_d8 + iVar8 + 4) = uVar7;
      cVar2 = (**(code **)(iVar10 + 8))(piVar9,iVar4,iVar11,uVar1);
      if (cVar2 != '\0') {
        return cVar2;
      }
      if (*(char *)(param_1 + 0x10) == '\x01') {
        return '\a';
      }
      uVar1 = *(undefined1 *)(param_1 + 0x18);
      cVar2 = flash_memory__60067e8c(param_1,param_2,uVar1);
      if (cVar2 != '\0') {
        return cVar2;
      }
      local_c8 = *(int **)(param_1 + 4);
      uVar7 = FUN_600d803e(param_1,param_2);
      cVar2 = (**(code **)(*local_c8 + 0x18))(local_c8,uVar7,iVar11,uVar1);
      if (cVar2 != '\0') {
        return cVar2;
      }
      uVar5 = (uint)*(byte *)(param_1 + 0x18);
      param_2 = param_2 + uVar5;
      param_3 = param_3 + uVar5;
      iVar3 = iVar3 + uVar5;
    }
    local_c4._0_1_ = '\0';
  }
  else {
    local_c4._0_1_ = '\x03';
  }
  return (char)local_c4;
}


