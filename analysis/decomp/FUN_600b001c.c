// 600b001c  FUN_600b001c  size=142 bytes
// --- callers ---
//   600acf50 FUN_600acf50
//   600f4d8e FUN_600f4d8e
// --- callees ---


int FUN_600b001c(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = (*(byte *)(param_1 + 0xf8) + 0x13) * 8 + param_1;
  local_c = 0;
  if (*(char *)(param_1 + 0xf8) != *(char *)(param_1 + 0xf9)) {
    local_c = DAT_600b00ac + (uint)*(ushort *)(iVar1 + 4) * 0x60 + 0x1248;
    *param_2 = *(undefined1 *)(iVar1 + 6);
    *(char *)(param_1 + 0xf8) = *(char *)(param_1 + 0xf8) + '\x01';
    *(byte *)(param_1 + 0xf8) =
         *(byte *)(param_1 + 0xf8) +
         (char)(uint)((ulonglong)DAT_600b00b0 * (ulonglong)*(byte *)(param_1 + 0xf8) >> 0x22) * -6;
  }
  return local_c;
}


