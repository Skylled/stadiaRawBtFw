// 600ad4f4  FUN_600ad4f4  size=278 bytes
// --- callers ---
//   600f5130 FUN_600f5130
//   600f5478 FUN_600f5478
// --- callees ---
//   600afb50 FUN_600afb50
//   600f6158 FUN_600f6158
//   600f6b96 FUN_600f6b96
//   600f6f52 FUN_600f6f52
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600ad4f4(int param_1,char param_2,undefined2 param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_27c;
  undefined2 local_27a;
  undefined1 local_278;
  undefined2 local_1a;
  int local_18;
  byte local_11;
  
  local_11 = FUN_600afb50(param_3);
  iVar1 = (uint)local_11 * 0x28 + DAT_600ad60c;
  local_18 = iVar1 + 0xa84;
  local_1a = CONCAT11(*(undefined1 *)(param_1 + 0xfb),*(undefined1 *)(iVar1 + 0xaa8));
  if (param_5 == 0) {
    param_5 = FUN_600f6158(param_1,param_2,param_3);
    FUN_600f6f52(param_1,*(undefined1 *)(local_18 + 0x24),1,1);
  }
  if (param_5 == 0) {
    uVar2 = 0x84;
  }
  else {
    thunk_EXT_FUN_0000b5ba(&local_27c,0,0x260);
    local_278 = param_2 == '\f';
    local_27c = param_3;
    local_27a = param_4;
    FUN_600f6b96(local_1a,param_5,1,&local_27c);
    uVar2 = 0x88;
  }
  return uVar2;
}


