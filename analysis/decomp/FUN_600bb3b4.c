// 600bb3b4  FUN_600bb3b4  size=146 bytes
// --- callers ---
//   600f7b26 FUN_600f7b26
// --- callees ---
//   600bcc30 FUN_600bcc30
//   600b5e00 FUN_600b5e00
//   6006ddd8 FUN_6006ddd8


undefined4 FUN_600bb3b4(undefined2 param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600bcc30(0,param_1);
  if (iVar1 == 0) {
    FUN_6006ddd8(param_2,DAT_600bb448,0x4dc);
    uVar2 = 0;
  }
  else if (*(ushort *)(iVar1 + 0x5c) < *(ushort *)(param_2 + 2)) {
    FUN_6006ddd8(param_2,DAT_600bb448,0x4f8);
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(param_2 + 6) = param_3;
    if (*(char *)(iVar1 + 0xa0) == '\0') {
      FUN_600b5e00(iVar1,0x1e,param_2);
      if (*(char *)(iVar1 + 0xa0) == '\0') {
        uVar2 = 1;
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      FUN_6006ddd8(param_2,DAT_600bb448,0x506);
      uVar2 = 0;
    }
  }
  return uVar2;
}


