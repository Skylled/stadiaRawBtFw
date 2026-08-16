// 600d3df4  FUN_600d3df4  size=44 bytes
// --- callers ---
//   6005ad74 application_state__6005ad74
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   60076400 FUN_60076400
//   6013d090 thunk_EXT_FUN_0000691c


void FUN_600d3df4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_14 = param_1;
  uStack_10 = param_2;
  uStack_c = param_3;
  iVar1 = FUN_60076400();
  thunk_EXT_FUN_00006a74(*(undefined4 *)(iVar1 + 0xec),&local_14,0xffffffff,0,param_1);
  iVar1 = FUN_60076400();
  thunk_EXT_FUN_0000691c(*(undefined4 *)(iVar1 + 0x78),8);
  return;
}


