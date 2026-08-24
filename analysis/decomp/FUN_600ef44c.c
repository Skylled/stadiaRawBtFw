// 600ef44c  FUN_600ef44c  size=42 bytes
// --- callers ---
//   60094a3c FUN_60094a3c
//   60094ba4 FUN_60094ba4
//   6009486c FUN_6009486c
// --- callees ---
//   6009506c FUN_6009506c


undefined4 FUN_600ef44c(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009506c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}


