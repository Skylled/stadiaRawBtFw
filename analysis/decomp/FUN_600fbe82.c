// 600fbe82  FUN_600fbe82  size=132 bytes
// --- callers ---
//   600fbf8a FUN_600fbf8a
// --- callees ---


void FUN_600fbe82(int param_1,undefined4 *param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)*param_2;
  *puVar1 = param_3;
  puVar1[1] = *(undefined1 *)(param_1 + 0x18e);
  puVar1[2] = *(undefined1 *)(param_1 + 400);
  puVar1[3] = *(undefined1 *)(param_1 + 0x192);
  puVar1[4] = *(undefined1 *)(param_1 + 0x1b1);
  puVar1[5] = *(undefined1 *)(param_1 + 0x1b4);
  puVar1[6] = *(undefined1 *)(param_1 + 0x1b5);
  *param_2 = puVar1 + 7;
  return;
}


