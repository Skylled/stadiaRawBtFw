// 600cc554  FUN_600cc554  size=30 bytes
// --- callers ---
//   600ca0fc FUN_600ca0fc
// --- callees ---


void FUN_600cc554(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + -0x20) = param_3;
  *(undefined4 *)(param_1 + -4) = 0x1000000;
  uVar1 = DAT_600cc574;
  *(uint *)(param_1 + -8) = param_2 & 0xfffffffe;
  *(undefined4 *)(param_1 + -0xc) = uVar1;
  *(undefined4 *)(param_1 + -0x24) = 0xfffffffd;
  return;
}


