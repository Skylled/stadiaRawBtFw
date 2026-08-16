// 600ad7fc  FUN_600ad7fc  size=102 bytes
// --- callers ---
//   600f5ce2 FUN_600f5ce2
// --- callees ---
//   6006de78 FUN_6006de78
//   6006dbac FUN_6006dbac


void FUN_600ad7fc(int param_1,byte param_2)

{
  undefined2 *puVar1;
  
  if (param_1 != 0) {
    *(byte *)(param_1 + 0xfc) = param_2;
    puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_600ad864,0x232);
    *puVar1 = 0x7100;
    puVar1[1] = 0;
    puVar1[2] = (ushort)param_2;
    puVar1[3] = (ushort)*(byte *)(param_1 + 0xfb);
    FUN_6006de78(1,0,puVar1,DAT_600ad864,0x238);
  }
  return;
}


