// 600dbea0  FUN_600dbea0  size=66 bytes
// --- callers ---
// --- callees ---
//   600dbda6 FUN_600dbda6
//   6013d290 thunk_EXT_FUN_00008ef2
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600dbea0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14 [2];
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x68);
  local_18 = param_2;
  local_14[0] = param_3;
  FUN_600dbda6(param_1 + 0xbc,&local_18,local_14);
  if (*(char *)(param_1 + 0x850) != '\0') {
    thunk_EXT_FUN_00008ef2(param_1 + 4);
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x68);
  return;
}


