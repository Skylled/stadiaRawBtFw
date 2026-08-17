// 6009af60  FUN_6009af60  size=110 bytes
// --- callers ---
//   600f303c FUN_600f303c
// --- callees ---
//   600c0434 FUN_600c0434
//   6009feb8 FUN_6009feb8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009b0a8 FUN_6009b0a8


void FUN_6009af60(undefined2 param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_c = DAT_6009afd0;
  local_10 = FUN_6009feb8(param_1);
  local_18 = 0;
  local_14 = 0;
  *(undefined2 *)(local_c + 0xaea) = param_3;
  thunk_EXT_FUN_0000b572(local_c + 0xae2,param_2,8);
  if ((local_10 != 0) && (iVar1 = FUN_600c0434(local_10 + 0x10), iVar1 == 0)) {
    FUN_6009b0a8(local_10 + 0x10,0,&local_18);
  }
  return;
}


