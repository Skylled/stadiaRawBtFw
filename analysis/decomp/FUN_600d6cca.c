// 600d6cca  FUN_600d6cca  size=46 bytes
// --- callers ---
//   600658b4 haptics_cluster__600658b4
// --- callees ---
//   600656a0 haptics__600656a0
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cef0 thunk_EXT_FUN_0000887a


undefined4 FUN_600d6cca(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char *local_14;
  undefined4 uStack_10;
  
  if (*param_1 == '\0') {
    uVar1 = 9;
  }
  else {
    local_14 = param_1 + 0xc;
    uStack_10 = param_3;
    thunk_EXT_FUN_0000b4c2();
    uVar1 = haptics__600656a0(param_1);
    thunk_EXT_FUN_0000887a(&local_14);
  }
  return uVar1;
}


