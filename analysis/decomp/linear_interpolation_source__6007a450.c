// 6007a450  linear_interpolation_source__6007a450  size=170 bytes
// src: linear_interpolation_source.h
// --- callers ---
//   600dba6a FUN_600dba6a
// --- callees ---
//   60101740 FUN_60101740
//   600d37ac FUN_600d37ac


/* src: linear_interpolation_source.h */

undefined4 linear_interpolation_source__6007a450(int *param_1,int param_2,uint param_3,int *param_4)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 *local_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2 [134];
  
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    if ((int)(param_3 << 0x1f) < 0) {
      local_b8 = DAT_6007a4fc;
      local_b4 = 0x28;
      local_b0 = local_a2;
      local_ac = 0x80;
      uStack_a8 = 0;
      local_a4 = 0;
      local_a3 = 0;
      local_a2[0] = 0;
      FUN_600d37ac(&local_b0,DAT_6007a500);
      FUN_60101740(&local_b8);
    }
    uVar3 = 0;
    while ((uVar3 != param_3 >> 1 && (iVar4 = *param_1, iVar4 != 0))) {
      iVar5 = param_1[1];
      param_1[1] = iVar5 + 1U;
      sVar1 = *(short *)((int)param_1 + iVar5 * 2 + 8);
      sVar1 = (short)(((int)*(short *)((int)param_1 + iVar5 * 2 + 0xc) - (int)sVar1) / (iVar4 + 1))
              + sVar1;
      *(short *)(param_2 + uVar3 * 2) = sVar1;
      *(short *)((int)param_1 + iVar5 * 2 + 8) = sVar1;
      if (1 < iVar5 + 1U) {
        param_1[1] = 0;
        *param_1 = iVar4 + -1;
      }
      uVar3 = uVar3 + 1;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = uVar3 << 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}


