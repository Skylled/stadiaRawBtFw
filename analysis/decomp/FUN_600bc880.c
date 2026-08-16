// 600bc880  FUN_600bc880  size=266 bytes
// --- callers ---
//   600b5720 FUN_600b5720
//   600b9e28 FUN_600b9e28
//   600b5264 FUN_600b5264
//   600b50d0 FUN_600b50d0
//   600b5540 FUN_600b5540
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600d9246 FUN_600d9246
//   600bbd3c FUN_600bbd3c


undefined4 FUN_600bc880(int param_1,ushort param_2,undefined4 *param_3)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + (param_2 + 0x20) * 4) == 0) {
    puVar1 = (ushort *)FUN_600bbd3c(0,0);
    if (puVar1 == (ushort *)0x0) {
      uVar2 = 0;
    }
    else {
      FUN_600aa3cc(param_1 + 0x44);
      *puVar1 = param_2;
      puVar1[1] = param_2;
      FUN_600d9246(puVar1 + 0x98);
      *(ushort **)(puVar1 + 0xa6) = puVar1;
      if (param_3 != (undefined4 *)0x0) {
        uVar2 = param_3[1];
        *(undefined4 *)(puVar1 + 0x3f) = *param_3;
        *(undefined4 *)(puVar1 + 0x41) = uVar2;
        puVar1[0x43] = *(ushort *)(param_3 + 2);
        *(undefined4 *)(puVar1 + 0x19) = *(undefined4 *)(puVar1 + 0x3f);
        *(undefined4 *)(puVar1 + 0x1b) = *(undefined4 *)(puVar1 + 0x41);
        puVar1[0x1d] = puVar1[0x43];
        *(undefined1 *)((int)puVar1 + 0xab) = 2;
        *(undefined1 *)(puVar1 + 0x56) = 2;
        *(undefined1 *)((int)puVar1 + 0xa9) = 2;
        *(undefined1 *)(puVar1 + 0x55) = 2;
        *(char *)((int)puVar1 + 0xb5) =
             (char)(uint)((ulonglong)DAT_600bc98c * (ulonglong)*(byte *)((int)param_3 + 1) >> 0x21);
      }
      *(ushort **)(param_1 + (param_2 + 0x20) * 4) = puVar1;
      *(int *)(puVar1 + 0x96) = param_1;
      if (*(char *)(param_1 + 1) == '\x04') {
        *(undefined1 *)(puVar1 + 2) = 6;
      }
      puVar1[0x90] = *(ushort *)((param_2 - 4) * 0x1c + DAT_600bc990 + 0xee6);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


