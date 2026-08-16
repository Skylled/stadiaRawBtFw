// 600ad868  FUN_600ad868  size=68 bytes
// --- callers ---
// --- callees ---
//   600ad9d8 FUN_600ad9d8
//   600af814 FUN_600af814
//   600f6132 FUN_600f6132
//   6006ddd8 FUN_6006ddd8


void FUN_600ad868(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_600af814(param_1,2);
  if ((iVar1 == 0) || (uVar2 = FUN_600f6132(iVar1), uVar2 < 4)) {
    FUN_6006ddd8(param_2,DAT_600ad8ac,0x26a);
  }
  else {
    FUN_600ad9d8(iVar1,param_2);
  }
  return;
}


