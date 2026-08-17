// 600c0cb4  FUN_600c0cb4  size=108 bytes
// --- callers ---
//   600c15a8 FUN_600c15a8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c0cb4(int *param_1,int param_2)

{
  undefined1 *puVar1;
  uint local_1c;
  undefined1 auStack_18 [4];
  int iStack_14;
  int local_10;
  undefined1 *local_c;
  
  local_c = (undefined1 *)((int)param_1 + 0x1b6);
  local_10 = param_2 + 8;
  for (local_1c = (uint)*(byte *)(param_2 + 4) + (uint)*(byte *)(param_2 + 5) * 0x100 +
                  (uint)*(byte *)(param_2 + 6) * 0x10000 & 0xfffff; DAT_600c0dac < local_1c;
      local_1c = local_1c >> 1) {
  }
  thunk_EXT_FUN_0000b5ba((int)param_1 + 0x1b6,0,0x10);
  *local_c = (char)local_1c;
  local_c[1] = (char)(local_1c >> 8);
  puVar1 = local_c + 3;
  local_c[2] = (char)(local_1c >> 0x10);
  local_c = local_c + 4;
  *puVar1 = (char)(local_1c >> 0x18);
  auStack_18[0] = 0;
  iStack_14 = (int)param_1 + 0x1b6;
  if (*param_1 != 0) {
    (*(code *)*param_1)(3,(int)param_1 + 0x1d,&local_1c);
  }
  if ((char)param_1[0x65] == '\a') {
    FUN_600c1a34(DAT_600c0db0,0x10,&local_1c);
  }
  else {
    FUN_600c1a34(param_1,0x10,auStack_18);
  }
  return;
}


