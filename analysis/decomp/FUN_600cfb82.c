// 600cfb82  FUN_600cfb82  size=116 bytes
// --- callers ---
//   60091d50 FUN_60091d50
//   600cbdc8 xbara__600cbdc8
//   60059e94 FUN_60059e94
// --- callees ---


undefined4 FUN_600cfb82(uint *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_1c;
  uint uStack_18;
  
  uStack_18 = param_3;
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar1 = 4;
  }
  else {
    uVar2 = 0;
LAB_600cfb92:
    do {
      if (-1 < (int)(*param_1 << 0x15)) {
        if (-1 < (int)(*param_1 << 0x13)) goto LAB_600cfb92;
      }
      uVar3 = uVar2 & 0xf;
      if ((int)(*param_1 << 0x13) < 0) {
        *param_1 = *param_1 | 0x1000;
        return 1;
      }
      uVar2 = uVar2 + 1;
      local_1c = param_1[uVar3 + 0x10];
      uVar4 = 0;
      uVar3 = param_3;
      if (3 < param_3) {
        uVar3 = 4;
      }
      do {
        *(undefined1 *)(param_2 + uVar4) = *(undefined1 *)((int)&local_1c + uVar4);
        uVar4 = uVar4 + 1;
      } while (uVar3 != uVar4);
      param_3 = param_3 - uVar3;
      param_2 = param_2 + uVar3;
    } while (param_3 != 0);
    uVar1 = 0;
  }
  return uVar1;
}


