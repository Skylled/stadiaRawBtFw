// 600f8ba8  FUN_600f8ba8  size=44 bytes
// --- callers ---
//   60098f88 FUN_60098f88
// --- callees ---
//   600bb6dc FUN_600bb6dc


undefined1 FUN_600f8ba8(undefined4 param_1)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0xff;
  iVar1 = FUN_600bb6dc(param_1,1);
  if (iVar1 != 0) {
    local_9 = *(undefined1 *)(iVar1 + 10);
  }
  return local_9;
}


