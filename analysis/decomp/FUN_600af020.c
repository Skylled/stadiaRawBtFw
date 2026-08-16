// 600af020  FUN_600af020  size=80 bytes
// --- callers ---
//   600af074 FUN_600af074
// --- callees ---
//   600d9290 FUN_600d9290
//   600f367e FUN_600f367e
//   600d92f8 FUN_600d92f8
//   6006ddd8 FUN_6006ddd8


void FUN_600af020(int param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined2 *)FUN_600d92f8(param_1 + 0x68);
  if (puVar1 != (undefined2 *)0x0) {
    FUN_600f367e(*puVar1,puVar1[1],puVar1[3],(int)puVar1 + 9);
    uVar2 = FUN_600d9290(param_1 + 0x68,puVar1);
    FUN_6006ddd8(uVar2,DAT_600af070,0x53a);
  }
  return;
}


