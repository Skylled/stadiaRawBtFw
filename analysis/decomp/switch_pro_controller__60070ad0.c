// 60070ad0  switch_pro_controller__60070ad0  size=236 bytes
// src: switch_pro_controller.cc
// --- callers ---
// --- callees ---
//   600d9700 FUN_600d9700
//   600d95c0 FUN_600d95c0
//   60050fd8 FUN_60050fd8


/* src: switch_pro_controller.cc */

void switch_pro_controller__60070ad0
               (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint in_fpscr;
  undefined4 in_cr0;
  undefined4 in_cr6;
  undefined4 in_cr7;
  float fVar8;
  float extraout_s13;
  float fVar9;
  float fVar10;
  char local_29;
  
  fVar10 = (float)VectorSignedToFloat(param_1 + -0x80,(byte)(in_fpscr >> 0x16) & 3);
  cVar2 = (char)param_2;
  local_29 = cVar2;
  if (param_2 == 0) {
    uVar5 = 0xff;
  }
  else if (param_2 == 0xff) {
    uVar5 = 0;
  }
  else {
    iVar1 = 2;
    pcVar7 = DAT_60070bc4;
    while (iVar6 = iVar1, 0 < iVar6) {
      iVar1 = iVar6 >> 1;
      iVar3 = FUN_600d95c0(pcVar7 + iVar1 * 2,&local_29);
      if (iVar3 != 0) {
        pcVar7 = pcVar7 + iVar1 * 2 + 2;
        iVar1 = (iVar6 - iVar1) + -1;
      }
    }
    uVar5 = (uint)(byte)pcVar7[-1] +
            (((int)pcVar7[1] - (int)pcVar7[-1]) * ((int)cVar2 - (int)pcVar7[-2])) /
            ((int)*pcVar7 - (int)pcVar7[-2]) & 0xff;
  }
  fVar9 = (float)VectorSignedToFloat(uVar5 - 0x80,(byte)(in_fpscr >> 0x16) & 3);
  fVar8 = (float)FUN_60050fd8(fVar9 * fVar9 + fVar10 * fVar10);
  coprocessor_function2(10,7,4,in_cr6,in_cr7,in_cr0);
  if (0.125 < extraout_s13 / DAT_60070bbc) {
    fVar8 = (extraout_s13 / DAT_60070bbc) / fVar8;
    uVar4 = FUN_600d9700(fVar8 * fVar10,DAT_60070bc0);
    *param_3 = uVar4;
    uVar4 = FUN_600d9700(fVar8 * fVar9,DAT_60070bc0);
    *param_4 = uVar4;
  }
  else {
    *param_3 = 0x800;
    *param_4 = 0x800;
  }
  return;
}


