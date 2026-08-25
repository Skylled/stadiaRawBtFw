// 600f3bde  FUN_600f3bde  size=100 bytes
// --- callers ---
//   600ad8fc FUN_600ad8fc
//   600f5a98 FUN_600f5a98
// --- callees ---
//   600af814 FUN_600af814
//   600f7a9c FUN_600f7a9c
//   600b4ec4 FUN_600b4ec4
//   600b4f34 FUN_600b4f34


void FUN_600f3bde(undefined4 param_1,short param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = FUN_600af814(param_1,param_3);
  if (iVar1 != 0) {
    if (*(short *)(iVar1 + 0x18) == 4) {
      if (param_2 == 0) {
        FUN_600b4f34(iVar1 + 0xd,0,2);
      }
      else {
        FUN_600f7a9c(param_1,4,param_2);
      }
    }
    else {
      FUN_600b4ec4(*(undefined2 *)(iVar1 + 0x18),param_2,0);
    }
  }
  return;
}


