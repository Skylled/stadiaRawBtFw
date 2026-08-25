// 600f7c6e  FUN_600f7c6e  size=50 bytes
// --- callers ---
//   600f6042 FUN_600f6042
//   600f5fb4 FUN_600f5fb4
// --- callees ---
//   600bb6dc FUN_600bb6dc


undefined2 FUN_600f7c6e(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 local_a;
  
  local_a = 0;
  iVar1 = FUN_600bb6dc(param_1,param_2);
  if (iVar1 != 0) {
    local_a = *(undefined2 *)(iVar1 + 0x30);
  }
  return local_a;
}


