// 600eb562  FUN_600eb562  size=38 bytes
// --- callers ---
//   600eb588 FUN_600eb588
// --- callees ---


void FUN_600eb562(byte *param_1,char *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = -(param_3 >> 5);
  uVar2 = param_3 & (param_3 >> 5) - 1 | 0x3f - param_3 & uVar1 & 0xff;
  *param_1 = (byte)uVar1 & 1;
  *param_2 = ((byte)uVar2 & 1) + (char)(uVar2 >> 1);
  return;
}


