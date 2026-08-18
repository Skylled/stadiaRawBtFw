// 600aff88  FUN_600aff88  size=144 bytes
// --- callers ---
//   600ffa34 FUN_600ffa34
// --- callees ---


void FUN_600aff88(int param_1,undefined2 param_2,char param_3,undefined1 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((*(byte *)(param_1 + 0xf9) + 0x13) * 8 + param_1);
  *(char *)((int)puVar1 + 7) = param_3;
  *(undefined1 *)((int)puVar1 + 6) = param_4;
  *puVar1 = param_5;
  *(undefined2 *)(puVar1 + 1) = param_2;
  if (param_3 == '\0') {
    *(undefined1 *)(param_1 + 0xf8) = *(undefined1 *)(param_1 + 0xf9);
  }
  *(char *)(param_1 + 0xf9) = *(char *)(param_1 + 0xf9) + '\x01';
  *(byte *)(param_1 + 0xf9) =
       *(byte *)(param_1 + 0xf9) +
       (char)(uint)((ulonglong)DAT_600b0018 * (ulonglong)*(byte *)(param_1 + 0xf9) >> 0x22) * -6;
  return;
}


