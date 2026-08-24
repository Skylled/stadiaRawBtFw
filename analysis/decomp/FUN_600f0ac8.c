// 600f0ac8  FUN_600f0ac8  size=62 bytes
// --- callers ---
//   600c0e7c FUN_600c0e7c
//   600c0e14 FUN_600c0e14
// --- callees ---
//   6009ff18 FUN_6009ff18


undefined1 FUN_600f0ac8(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_6009ff18(param_1);
  if ((iVar1 != 0) && (*(short *)(iVar1 + 0xd6) != 0)) {
    local_9 = 1;
    *param_2 = *(undefined2 *)(iVar1 + 0xd6);
  }
  return local_9;
}


