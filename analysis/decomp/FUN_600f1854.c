// 600f1854  FUN_600f1854  size=68 bytes
// --- callers ---
//   600fcfa0 FUN_600fcfa0
// --- callees ---
//   600b4798 FUN_600b4798


undefined1 FUN_600f1854(char param_1)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 0;
  if ((param_1 < -0x46) || ('\x14' < param_1)) {
    local_9 = 5;
  }
  else {
    iVar1 = FUN_600b4798((int)param_1);
    if (iVar1 == 0) {
      local_9 = 3;
    }
  }
  return local_9;
}


