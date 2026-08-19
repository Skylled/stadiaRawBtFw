// 600deb98  FUN_600deb98  size=22 bytes
// --- callers ---
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600deb98(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  (**(code **)*puVar1)(puVar1);
  thunk_EXT_FUN_0000b52a(puVar1);
  return;
}


