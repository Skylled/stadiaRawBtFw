// 600f6042  FUN_600f6042  size=128 bytes
// --- callers ---
// --- callees ---
//   600f7c6e FUN_600f7c6e
//   600f20ac FUN_600f20ac
//   600ada6c FUN_600ada6c
//   600afea0 FUN_600afea0
//   600b02e0 FUN_600b02e0
//   600af718 FUN_600af718


void FUN_600f6042(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_a;
  
  iVar1 = FUN_600afea0(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_600af718(iVar1 + 0xd);
    if ((iVar2 == 0) && (iVar2 = FUN_600f20ac(iVar1 + 0xd), iVar2 != 0)) {
      FUN_600ada6c(iVar1 + 0xd);
    }
    local_a = FUN_600f7c6e(iVar1 + 0xd,*(undefined1 *)(iVar1 + 0x13));
    if (local_a == 0) {
      local_a = 0x16;
    }
    FUN_600b02e0(iVar1 + 0xd,local_a,1);
  }
  return;
}


