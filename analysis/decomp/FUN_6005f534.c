// 6005f534  FUN_6005f534  size=144 bytes
// --- callers ---
//   600d9b7c FUN_600d9b7c
//   6005fcc0 FUN_6005fcc0
//   6006efd4 FUN_6006efd4
//   60060910 FUN_60060910
//   60060b64 uart__60060b64
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   6005f610 FUN_6005f610
//   60060fe8 usb_device__60060fe8
//   60061a98 hardware_timer__60061a98
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6005f534(short *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar4 = (uint)*param_1;
  uVar3 = (*(uint *)(DAT_6005f5c4 + 0xc) & 0x7ff) >> 8;
  uVar6 = 7 - uVar3;
  if (3 < uVar6) {
    uVar6 = 4;
  }
  if (uVar3 + 4 < 7) {
    uVar3 = 0;
  }
  else {
    uVar3 = uVar3 - 3;
  }
  uVar2 = (undefined1)
          (((*(uint *)(param_1 + 2) & ~(-1 << (uVar6 & 0xff))) << (uVar3 & 0xff) & 0xf) << 4);
  if ((int)uVar4 < 0) {
    *(undefined1 *)(DAT_6005f5d0 + (uVar4 & 0xf)) = uVar2;
  }
  else {
    (&DAT_e000e400)[uVar4] = uVar2;
  }
  uVar3 = (uint)*param_1;
  if (-1 < (int)uVar3) {
    *(int *)(DAT_6005f5c8 + (uVar3 >> 5) * 4) = 1 << (uVar3 & 0x1f);
  }
  if (*(int *)(param_1 + 4) != 0) {
    uVar3 = *(int *)(param_1 + 4) - 1;
    if (4 < uVar3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0x6005f5c2);
      (*pcVar1)();
    }
    iVar5 = *(int *)(DAT_6005f5cc + uVar3 * 4);
    *(uint *)(iVar5 + 0x14) = 1 << (*(uint *)(param_1 + 6) & 0xff) | *(uint *)(iVar5 + 0x14);
  }
  return;
}


