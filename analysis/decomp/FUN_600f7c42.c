// 600f7c42  FUN_600f7c42  size=44 bytes
// --- callers ---
//   600c1788 FUN_600c1788
//   600c6654 FUN_600c6654
//   600c1864 FUN_600c1864
//   600fee40 FUN_600fee40
// --- callees ---
//   600bb6dc FUN_600bb6dc


undefined1 FUN_600f7c42(undefined4 param_1)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0xff;
  iVar1 = FUN_600bb6dc(param_1,2);
  if (iVar1 != 0) {
    local_9 = *(undefined1 *)(iVar1 + 10);
  }
  return local_9;
}


