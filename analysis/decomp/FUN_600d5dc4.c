// 600d5dc4  FUN_600d5dc4  size=80 bytes
// --- callers ---
//   60063e24 usb_host_audio_topology__60063e24
//   600d600a FUN_600d600a
// --- callees ---
//   60063c58 FUN_60063c58


undefined4 * FUN_600d5dc4(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uStack_1c;
  uint uStack_18;
  
  iVar3 = *(int *)(param_2 + 0x5c);
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (iVar3 != 0) {
    uStack_1c = param_2 & 0xffffff;
    puVar4 = param_1;
    uStack_18 = param_3;
    while (uStack_1c >> 0x18 < (uint)*(byte *)(iVar3 + 0x40a)) {
      iVar1 = *(int *)(iVar3 + (uStack_1c >> 0x18) * 0x40 + 0x30);
      if ((*(char *)(iVar1 + 5) == '\x01') && (uVar2 = (uint)*(byte *)(iVar1 + 6), uVar2 == param_3)
         ) {
        FUN_60063c58(param_1,(int)&uStack_1c + 3,1,uVar2,puVar4);
      }
      uStack_1c = CONCAT13(uStack_1c._3_1_ + '\x01',(undefined3)uStack_1c);
    }
  }
  return param_1;
}


