// 600c6f50  FUN_600c6f50  size=142 bytes
// --- callers ---
//   600c7048 FUN_600c7048
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600c6f50(int param_1,byte param_2,byte param_3)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined2 local_10;
  byte local_9;
  
  local_18 = *DAT_600c6fe0;
  uStack_14 = DAT_600c6fe0[1];
  local_10 = (undefined2)DAT_600c6fe0[2];
  if ((param_3 < param_2) || (0x4e < param_3)) {
    uVar1 = 0;
  }
  else {
    thunk_EXT_FUN_0000b572(param_1,&local_18,10);
    for (local_9 = param_2; local_9 <= param_3; local_9 = local_9 + 1) {
      *(byte *)((uint)(local_9 >> 3) + param_1) =
           ~(byte)(1 << (local_9 & 7)) & *(byte *)((uint)(local_9 >> 3) + param_1);
    }
    uVar1 = 1;
  }
  return uVar1;
}


