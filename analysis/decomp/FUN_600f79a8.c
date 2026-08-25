// 600f79a8  FUN_600f79a8  size=140 bytes
// --- callers ---
//   600f5ede FUN_600f5ede
//   600bdf3c FUN_600bdf3c
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600bcc30 FUN_600bcc30


undefined4 FUN_600f79a8(undefined2 param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600bcc30(0,param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((*param_2 == 0) || (*param_2 == 4)) {
      FUN_600b5e00(iVar1,0x19,param_2);
    }
    else {
      *(undefined1 *)(param_2 + 0x12) = 0;
      if ((char)param_2[1] != '\0') {
        *(undefined1 *)(iVar1 + 0x5a) = 0;
      }
      if ((char)param_2[0x10] != '\0') {
        *(undefined1 *)(iVar1 + 0x78) = 0;
      }
      if ((char)param_2[3] != '\0') {
        *(undefined1 *)(iVar1 + 0x5e) = 0;
      }
      FUN_600b5e00(iVar1,0x1a,param_2);
    }
    uVar2 = 1;
  }
  return uVar2;
}


