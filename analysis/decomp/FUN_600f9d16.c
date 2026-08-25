// 600f9d16  FUN_600f9d16  size=158 bytes
// --- callers ---
//   600a67ec FUN_600a67ec
//   6009b5b4 FUN_6009b5b4
//   600a59d0 FUN_600a59d0
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600aa340 FUN_600aa340
//   600b218c FUN_600b218c
//   600bcbe0 FUN_600bcbe0


undefined4 FUN_600f9d16(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_a;
  
  iVar1 = FUN_600bcbe0(param_1);
  if (iVar1 == 0) {
    uVar3 = 1;
  }
  else {
    *(undefined1 *)(iVar1 + 0x16) = 0;
    if (*(int *)(iVar1 + 0x5c) == 0) {
      if (((*(char *)(iVar1 + 1) == '\x04') || (*(char *)(iVar1 + 1) == '\x03')) ||
         (*(char *)(iVar1 + 1) == '\x05')) {
        if (*(short *)(iVar1 + 0x14) == 0) {
          iVar2 = FUN_600b218c(*(undefined2 *)(iVar1 + 2),0x13);
          if (iVar2 == 0) {
            local_a = 2;
          }
          else {
            *(undefined1 *)(iVar1 + 1) = 5;
            local_a = 0x1e;
          }
        }
        else {
          local_a = 3;
        }
        if (local_a != -1) {
          FUN_600aa340(iVar1 + 0x44,2,local_a);
        }
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


