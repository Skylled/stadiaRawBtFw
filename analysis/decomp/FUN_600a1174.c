// 600a1174  FUN_600a1174  size=72 bytes
// --- callers ---
//   6006c088 FUN_6006c088
//   600c5798 FUN_600c5798
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600a1174(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_18 [8];
  undefined4 local_10;
  undefined1 local_9;
  
  local_9 = 3;
  if (*(int *)(DAT_600a11bc + 0xd4) != 0) {
    thunk_EXT_FUN_0000b572(auStack_18,param_1,6,auStack_18,param_2);
    local_10 = param_2;
    local_9 = (**(code **)(DAT_600a11bc + 0xd4))(0x10,auStack_18);
  }
  return local_9;
}


