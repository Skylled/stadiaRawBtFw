// 600f6b4a  FUN_600f6b4a  size=76 bytes
// --- callers ---
//   600adeb4 FUN_600adeb4
//   600aeb14 FUN_600aeb14
//   600aed40 FUN_600aed40
//   600ae90c FUN_600ae90c
// --- callees ---
//   600f194c FUN_600f194c
//   600f0994 FUN_600f0994


void FUN_600f6b4a(undefined4 param_1,undefined1 param_2,byte *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  byte local_9;
  
  local_9 = 0;
  FUN_600f194c(param_1,&local_9,param_2);
  local_9 = local_9 & 0x34;
  uVar1 = FUN_600f0994(param_1,param_2);
  *param_4 = uVar1;
  *param_3 = local_9;
  return;
}


