// 600ada6c  FUN_600ada6c  size=102 bytes
// --- callers ---
//   600f5fb4 FUN_600f5fb4
//   600f5ede FUN_600f5ede
//   600f5bfc FUN_600f5bfc
//   600f6042 FUN_600f6042
// --- callees ---
//   600af350 FUN_600af350
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600ada6c(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_18 [6];
  undefined1 local_12;
  undefined1 auStack_10 [6];
  undefined1 local_a;
  
  thunk_EXT_FUN_0000b572(auStack_18,param_1,6);
  local_12 = 0;
  iVar1 = FUN_600af350(auStack_18);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b572(auStack_10,param_1,6);
    local_a = 0;
    if (*(int *)(DAT_600adad4 + 0x1558) != 0) {
      (**(code **)(DAT_600adad4 + 0x1558))(1,auStack_10,0);
    }
  }
  return;
}


