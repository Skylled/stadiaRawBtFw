// 600cc1f4  FUN_600cc1f4  size=162 bytes
// --- callers ---
//   600cbc60 FUN_600cbc60
// --- callees ---


void FUN_600cc1f4(byte *param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  
  iVar1 = DAT_600cc298;
  while( true ) {
    iVar2 = DAT_600cc298;
    if (param_2 < 3) break;
    param_2 = param_2 - 3;
    *param_3 = *(undefined1 *)(iVar1 + (uint)(*param_1 >> 2));
    param_3[1] = *(undefined1 *)(iVar1 + ((*param_1 & 3) << 4 | (uint)(param_1[1] >> 4)));
    param_3[2] = *(undefined1 *)(iVar1 + ((param_1[1] & 0xf) << 2 | (uint)(param_1[2] >> 6)));
    param_3[3] = *(undefined1 *)(iVar1 + (param_1[2] & 0x3f));
    param_1 = param_1 + 3;
    param_3 = param_3 + 4;
  }
  if (param_2 != 0) {
    *param_3 = *(undefined1 *)(DAT_600cc298 + (uint)(*param_1 >> 2));
    uVar4 = (*param_1 & 3) * 0x10;
    if (param_2 == 1) {
      param_3[1] = *(undefined1 *)(iVar2 + uVar4);
      uVar3 = 0x3d;
    }
    else {
      param_3[1] = *(undefined1 *)(iVar2 + (uVar4 | param_1[1] >> 4));
      uVar3 = *(undefined1 *)(iVar2 + (param_1[1] & 0xf) * 4);
    }
    param_3[2] = uVar3;
    param_3[3] = 0x3d;
  }
  return;
}


