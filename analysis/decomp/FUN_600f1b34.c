// 600f1b34  FUN_600f1b34  size=62 bytes
// --- callers ---
//   600c2c04 FUN_600c2c04
// --- callees ---
//   600a44bc FUN_600a44bc
//   600f0910 FUN_600f0910


undefined4 FUN_600f1b34(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 1;
  iVar1 = FUN_600f0910(param_1);
  if (iVar1 != 0) {
    local_9 = 2;
  }
  uVar2 = FUN_600a44bc(param_1,local_9,param_2,param_3,param_4);
  return uVar2;
}


