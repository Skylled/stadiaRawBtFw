// 600f4322  FUN_600f4322  size=84 bytes
// --- callers ---
//   600ac734 FUN_600ac734
// --- callees ---
//   600f194c FUN_600f194c


undefined1 FUN_600f4322(int param_1)

{
  byte local_a;
  undefined1 local_9;
  
  local_9 = 0x8e;
  local_a = 0;
  FUN_600f194c(param_1 + 0xd,&local_a,*(undefined1 *)(param_1 + 0x13));
  if ((((local_a & 4) != 0) && ((local_a & 0x10) != 0)) && (local_9 = 0x8d, (local_a & 2) != 0)) {
    local_9 = 0;
  }
  return local_9;
}


