// 600bde90  FUN_600bde90  size=168 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f7912 FUN_600f7912
//   600f77cc FUN_600f77cc
//   600bf328 FUN_600bf328


void FUN_600bde90(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  undefined1 auStack_54 [36];
  char local_30;
  char local_2e;
  undefined1 *local_c;
  
  local_c = (undefined1 *)FUN_600bf328();
  if (local_c != (undefined1 *)0x0) {
    *local_c = 2;
    thunk_EXT_FUN_0000b572(local_c + 2,param_1,6);
    *(undefined2 *)(local_c + 0x22) = param_2;
    FUN_600f77cc(param_1,param_4,param_2,0,0);
    thunk_EXT_FUN_0000b572(auStack_54,DAT_600bdf38,0x48);
    iVar1 = FUN_600f7912(param_2,auStack_54);
    if (((iVar1 == 0) && (local_30 != '\0')) && (local_2e != '\0')) {
      local_2e = 0;
      local_30 = 0;
      FUN_600f7912(param_2,auStack_54);
    }
  }
  return;
}


