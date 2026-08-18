// 600c65b0  FUN_600c65b0  size=158 bytes
// --- callers ---
//   600fde94 FUN_600fde94
//   600fd6d6 FUN_600fd6d6
// --- callees ---
//   60094fac FUN_60094fac
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ab9b8 FUN_600ab9b8


void FUN_600c65b0(undefined4 *param_1)

{
  int iVar1;
  undefined1 local_2c4;
  undefined1 local_2c3;
  code *local_14;
  undefined1 local_d;
  char *local_c;
  
  local_c = DAT_600c6650;
  local_d = *(undefined1 *)((int)param_1 + 5);
  local_14 = (code *)*param_1;
  thunk_EXT_FUN_0000b5ba(&local_2c4,0,0x2b0);
  FUN_600ab9b8(*(undefined1 *)((int)param_1 + 5));
  thunk_EXT_FUN_0000b5ba(param_1,0,0x10c);
  local_2c3 = local_d;
  local_2c4 = 0;
  if (local_14 != (code *)0x0) {
    (*local_14)(1,&local_2c4);
  }
  iVar1 = FUN_60094fac();
  if ((iVar1 == 0) && (*local_c == '\x03')) {
    *local_c = '\0';
  }
  return;
}


