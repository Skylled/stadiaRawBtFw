// 600f0994  FUN_600f0994  size=64 bytes
// --- callers ---
//   600f6b4a FUN_600f6b4a
// --- callees ---
//   6009ff18 FUN_6009ff18


undefined1 FUN_600f0994(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    if (param_2 == '\x01') {
      local_9 = *(undefined1 *)(iVar1 + 0x60);
    }
    else {
      local_9 = *(undefined1 *)(iVar1 + 0x61);
    }
  }
  return local_9;
}


