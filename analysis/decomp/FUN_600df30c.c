// 600df30c  FUN_600df30c  size=90 bytes
// --- callers ---
//   600df264 state_machine__600df264
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   601017fc FUN_601017fc
//   60101818 FUN_60101818


undefined1
FUN_600df30c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined1 local_90 [4];
  undefined4 local_8c;
  undefined1 *puStack_88;
  undefined1 *puStack_84;
  undefined4 uStack_80;
  undefined1 auStack_7c [80];
  undefined4 local_2c;
  
  local_2c = 0;
  FUN_601017fc(auStack_7c);
  puStack_88 = local_90;
  local_90[0] = 0xd;
  uStack_80 = param_5;
  local_8c = param_2;
  puStack_84 = auStack_7c;
  thunk_EXT_FUN_00006a74(*(undefined4 *)(param_1 + 0x2188),&local_8c,0xffffffff,0);
  FUN_60101818(auStack_7c);
  return local_90[0];
}


