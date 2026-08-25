// 600fbf06  FUN_600fbf06  size=132 bytes
// --- callers ---
//   600fbf8a FUN_600fbf8a
// --- callees ---


void FUN_600fbf06(int param_1,undefined4 *param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *puVar1 = param_3;
  puVar1[1] = *(undefined1 *)(param_1 + 0x18d);
  puVar1[2] = *(undefined1 *)(param_1 + 399);
  puVar1[3] = *(undefined1 *)(param_1 + 0x191);
  puVar1[4] = *(undefined1 *)(param_1 + 0x1b0);
  puVar1[5] = *(undefined1 *)(param_1 + 0x1b2);
  puVar1[6] = *(undefined1 *)(param_1 + 0x1b3);
  *param_2 = puVar1 + 7;
  return;
}


