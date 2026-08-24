// 600edfda  thunk_FUN_600921b8  size=4 bytes
// --- callers ---
//   60078340 firmware_image_upload__60078340
// --- callees ---


uint thunk_FUN_600921b8(uint param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar2;
  
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  param_1 = ~param_1;
  while( true ) {
    if (param_3 == 0) goto LAB_6009222a;
    if (((uint)param_2 & 3) == 0) break;
    param_3 = param_3 - 1;
    param_1 = *(uint *)(DAT_60092444 + (((byte)*param_2 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
    param_2 = (uint *)((int)param_2 + 1);
  }
  uVar5 = param_3 >> 5;
  puVar2 = param_2;
  while (puVar2 + 8 != param_2 + uVar5 * 8 + 8) {
    param_1 = *puVar2 ^ param_1;
    uVar4 = *(uint *)(DAT_60092444 + ((param_1 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (param_1 >> 0x18) * 4) ^ puVar2[1] ^
            *(uint *)(DAT_60092444 + (((param_1 & 0xffff) >> 8) + 0x200) * 4) ^
            *(uint *)(DAT_60092444 + (((param_1 & 0xffffff) >> 0x10) + 0x100) * 4);
    uVar4 = *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4) ^
            *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[2] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4);
    uVar4 = *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4) ^
            *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[3] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4);
    uVar4 = *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4) ^
            *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[4] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4);
    uVar4 = *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4) ^
            *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[5] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4);
    uVar4 = *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[6] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4) ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4);
    uVar4 = *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
            *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^ puVar2[7] ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4) ^
            *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4);
    param_1 = *(uint *)(DAT_60092444 + (((uVar4 & 0xffffff) >> 0x10) + 0x100) * 4) ^
              *(uint *)(DAT_60092444 + ((uVar4 & 0xff) + 0x300) * 4) ^
              *(uint *)(DAT_60092444 + (uVar4 >> 0x18) * 4) ^
              *(uint *)(DAT_60092444 + (((uVar4 & 0xffff) >> 8) + 0x200) * 4);
    puVar2 = puVar2 + 8;
  }
  param_3 = uVar5 * -0x20 + param_3;
  param_2 = param_2 + uVar5 * 8;
  for (puVar2 = param_2; (byte *)0x3 < (byte *)((int)param_2 + (param_3 - (int)puVar2));
      puVar2 = puVar2 + 1) {
    param_1 = *puVar2 ^ param_1;
    param_1 = *(uint *)(DAT_60092444 + (((param_1 & 0xffffff) >> 0x10) + 0x100) * 4) ^
              *(uint *)(DAT_60092444 + ((param_1 & 0xff) + 0x300) * 4) ^
              *(uint *)(DAT_60092444 + (param_1 >> 0x18) * 4) ^
              *(uint *)(DAT_60092444 + (((param_1 & 0xffff) >> 8) + 0x200) * 4);
  }
  iVar3 = (param_3 >> 2) * -4 + param_3;
  if (iVar3 != 0) {
    puVar2 = param_2 + (param_3 >> 2);
    do {
      puVar1 = (uint *)((int)puVar2 + 1);
      param_1 = *(uint *)(DAT_60092444 + (((byte)*puVar2 ^ param_1) & 0xff) * 4) ^ param_1 >> 8;
      puVar2 = puVar1;
    } while ((uint *)(iVar3 + (int)(param_2 + (param_3 >> 2))) != puVar1);
  }
LAB_6009222a:
  return ~param_1;
}


