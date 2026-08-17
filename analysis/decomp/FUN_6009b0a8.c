// 6009b0a8  FUN_6009b0a8  size=134 bytes
// --- callers ---
//   6009af60 FUN_6009af60
//   600fad92 FUN_600fad92
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600b14b8 FUN_600b14b8
//   600b1558 FUN_600b1558


void FUN_6009b0a8(undefined4 param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_6009ff18(param_1);
  iVar1 = DAT_6009b130;
  if (iVar2 != 0) {
    *(undefined2 *)(DAT_6009b130 + 0xae0) = *(undefined2 *)(iVar2 + 0x5e);
    *(undefined1 *)(iVar1 + 0xaec) = *(undefined1 *)(iVar2 + 0xd9);
    if (param_2 == '\0') {
      if ((*(byte *)(iVar2 + 0x7b) & 0x10) == 0) {
        FUN_600b1558(*(undefined2 *)(DAT_6009b130 + 0xae0));
      }
      else {
        FUN_600b14b8(*(undefined2 *)(DAT_6009b130 + 0xae0),iVar2 + 0xac);
      }
    }
    else {
      FUN_600b14b8(*(undefined2 *)(DAT_6009b130 + 0xae0),param_3);
    }
  }
  return;
}


