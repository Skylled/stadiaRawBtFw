// 600ee9f6  FUN_600ee9f6  size=176 bytes
// --- callers ---
//   60094ba4 FUN_60094ba4
//   6009486c FUN_6009486c
//   600eead0 FUN_600eead0
//   600eeb42 FUN_600eeb42
// --- callees ---
//   600ee97a FUN_600ee97a
//   600ee57a FUN_600ee57a
//   600d9198 FUN_600d9198
//   6009506c FUN_6009506c


void FUN_600ee9f6(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)*(byte *)(param_2 + 0x2c) * 0x1c + *(int *)(param_2 + 0x28);
  iVar1 = FUN_6009506c(param_1);
  *(undefined1 *)(param_2 + 0x2e) = *(undefined1 *)(param_2 + 0x2f);
  *(undefined1 *)(param_2 + 0x2d) = *(undefined1 *)(param_2 + 0x2e);
  if (iVar1 != 0) {
    if ((*(byte *)(param_2 + 0x2c) < *(byte *)(param_2 + 0x2f)) &&
       (iVar2 = FUN_600ee57a(param_2,*(undefined2 *)(iVar2 + 0x14),*(undefined2 *)(iVar2 + 0x16),
                             iVar2,*(undefined1 *)(iVar2 + 0x18),*(undefined1 *)(iVar2 + 0x19)),
       iVar2 == 0)) {
      FUN_600ee97a(param_1,param_2);
      return;
    }
    *(undefined1 *)(*(int *)(iVar1 + 0x10) + 8) = 2;
    FUN_600d9198(param_2 + 1,0x1d13,param_1,1);
  }
  return;
}


