// 600c4af8  FUN_600c4af8  size=60 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c4af8(undefined4 param_1)

{
  undefined1 auStack_10 [6];
  undefined1 local_a;
  
  thunk_EXT_FUN_0000b572(auStack_10,param_1,6);
  local_a = 0;
  if (*(int *)(DAT_600c4b34 + 0xe8) != 0) {
    (**(code **)(DAT_600c4b34 + 0xe8))(0,auStack_10);
  }
  return;
}


