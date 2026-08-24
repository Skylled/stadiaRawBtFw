// 600f2262  FUN_600f2262  size=96 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a6b20 FUN_600a6b20
//   60099584 FUN_60099584


void FUN_600f2262(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  
  uVar1 = *param_1;
  sVar3 = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
  uVar2 = param_1[3];
  FUN_60099584(sVar3,uVar1,uVar2);
  FUN_600a6b20(sVar3,uVar1,uVar2);
  return;
}


