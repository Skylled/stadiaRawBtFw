// 600d6cf8  FUN_600d6cf8  size=50 bytes
// --- callers ---
//   600658b4 haptics_cluster__600658b4
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6006573c haptics__6006573c
//   6013cef0 thunk_EXT_FUN_0000887a


undefined4 FUN_600d6cf8(char *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *local_14;
  
  if (*param_1 == '\0') {
    uVar1 = 9;
  }
  else {
    local_14 = param_1 + 0xc;
    thunk_EXT_FUN_0000b4c2();
    uVar1 = haptics__6006573c(param_1,param_2);
    thunk_EXT_FUN_0000887a(&local_14);
  }
  return uVar1;
}


