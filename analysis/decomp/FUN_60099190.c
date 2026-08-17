// 60099190  FUN_60099190  size=102 bytes
// --- callers ---
//   60099204 FUN_60099204
//   60099584 FUN_60099584
//   6009a5b0 FUN_6009a5b0
//   60099dd0 FUN_60099dd0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_60099190(undefined1 param_1,int param_2)

{
  int iVar1;
  undefined1 local_10 [8];
  
  if (((*(int *)(DAT_600991f8 + 2000) != 0) && (param_2 != 0)) &&
     (iVar1 = thunk_EXT_FUN_0000b554(DAT_600991fc,param_2,6), iVar1 == 0)) {
    thunk_EXT_FUN_0000b572(local_10,DAT_60099200,8);
    local_10[0] = param_1;
    (**(code **)(DAT_600991f8 + 2000))(local_10);
    thunk_EXT_FUN_0000b5ba(DAT_60099200,0,8);
    *(undefined4 *)(DAT_600991f8 + 2000) = 0;
  }
  return;
}


