// 600ef6ec  FUN_600ef6ec  size=268 bytes
// --- callers ---
//   600fe500 FUN_600fe500
// --- callees ---
//   600eef06 FUN_600eef06
//   600ef2da FUN_600ef2da


undefined1 FUN_600ef6ec(undefined4 param_1,undefined4 param_2,int param_3,byte *param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  short local_1c;
  undefined1 local_19;
  byte *local_18;
  byte local_11;
  
  local_11 = 0;
  local_18 = (byte *)(param_3 + 9);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_30 = 2;
  local_2c = 0x2905;
  local_19 = 0;
  iVar1 = FUN_600ef2da(&local_30,param_2,1);
  if (iVar1 == 0) {
    *(undefined2 *)param_4 = *(undefined2 *)(param_3 + 6);
    *(int *)(param_4 + 4) = param_3 + 9;
  }
  else {
    while( true ) {
      if ((*(ushort *)(param_3 + 6) < 2) || (9 < local_11)) goto LAB_600ef7d0;
      local_1c = (ushort)local_18[1] * 0x100 + (ushort)*local_18;
      local_18 = local_18 + 2;
      iVar1 = FUN_600eef06(param_1,local_1c,param_4 + (uint)local_11 * 0x4c + 4,
                           param_4 + (uint)local_11 * 0x4c + 0x20,
                           param_4 + (uint)local_11 * 0x4c + 0x38);
      if (iVar1 == 0) break;
      local_11 = local_11 + 1;
      *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + -2;
    }
    local_19 = 0x81;
LAB_600ef7d0:
    *param_4 = local_11;
  }
  return local_19;
}


