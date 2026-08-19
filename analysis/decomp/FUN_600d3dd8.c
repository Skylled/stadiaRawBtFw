// 600d3dd8  FUN_600d3dd8  size=28 bytes
// --- callers ---
//   600d41ec FUN_600d41ec
//   6005c570 FUN_6005c570
//   6005b8dc application_state__6005b8dc
//   600df224 FUN_600df224
//   6005c8a0 FUN_6005c8a0
//   600db408 FUN_600db408
//   6005d12c FUN_6005d12c
//   600d4224 FUN_600d4224
//   60082b08 FUN_60082b08
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   6005bdac FUN_6005bdac
//   6013d398 thunk_EXT_FUN_00001834


void FUN_600d3dd8(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  uVar1 = FUN_6005bdac();
  thunk_EXT_FUN_00001834(uVar1,param_1,param_2,0,0,uVar2);
  return;
}


