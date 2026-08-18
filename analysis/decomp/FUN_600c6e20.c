// 600c6e20  FUN_600c6e20  size=110 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ab318 FUN_600ab318


void FUN_600c6e20(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_20 [2];
  undefined2 local_1e;
  undefined1 local_1c;
  int local_c;
  
  iVar1 = (uint)*(byte *)(param_1 + 0x17) * 0x20 + DAT_600c6e90;
  local_c = iVar1 + 4;
  local_20[0] = *(undefined1 *)(iVar1 + 0x20);
  local_1e = *(undefined2 *)(param_2 + 6);
  iVar1 = FUN_600ab318(*(undefined1 *)(iVar1 + 0x20),param_1,*(undefined1 *)(param_1 + 0x16));
  if (iVar1 == 0) {
    local_1c = 0x85;
  }
  else {
    local_1c = 0;
    thunk_EXT_FUN_0000b5ba(param_1,0,0x1c);
  }
  if (*(int *)(local_c + 0x18) != 0) {
    (**(code **)(local_c + 0x18))(0xb,local_20);
  }
  return;
}


