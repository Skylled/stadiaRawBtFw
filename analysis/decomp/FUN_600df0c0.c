// 600df0c0  FUN_600df0c0  size=48 bytes
// --- callers ---
//   600df0f0 FUN_600df0f0
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   600801dc FUN_600801dc
//   6013d3d8 thunk_EXT_FUN_0000b4c2


void FUN_600df0c0(int param_1,int param_2,undefined4 param_3)

{
  int local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  thunk_EXT_FUN_0000b4c2(param_1 + 0xbc);
  if ((*(char *)(param_1 + 0x158) != '\0') && (*(int *)(param_1 + 0x14c) == 0)) {
    local_14 = *(int *)(param_1 + 0x14c);
    FUN_600801dc(param_1,&local_14);
  }
  thunk_EXT_FUN_00007d10(param_1 + 0xbc);
  return;
}


