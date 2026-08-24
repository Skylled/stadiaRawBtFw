// 600f14f8  FUN_600f14f8  size=154 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a30f0 FUN_600a30f0
//   600a59d0 FUN_600a59d0
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f14f8(char param_1,undefined4 param_2,short param_3,undefined4 param_4)

{
  undefined1 auStack_10c [251];
  undefined1 local_11;
  
  local_11 = 0;
  thunk_EXT_FUN_0000b5ba(auStack_10c,0,0xf9);
  thunk_EXT_FUN_0000b572(auStack_10c,param_4,param_3);
  if ((param_1 == '\0') || (param_3 == 0)) {
    local_11 = 0x10;
  }
  FUN_600a30f0(param_2,auStack_10c,param_3,local_11);
  FUN_600a59d0(param_2,param_4,local_11);
  return;
}


