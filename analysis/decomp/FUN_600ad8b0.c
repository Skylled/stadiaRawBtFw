// 600ad8b0  FUN_600ad8b0  size=70 bytes
// --- callers ---
// --- callees ---
//   600f6132 FUN_600f6132
//   600ad9d8 FUN_600ad9d8
//   600afea0 FUN_600afea0
//   6006ddd8 FUN_6006ddd8


void FUN_600ad8b0(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600afea0(param_1);
  if ((iVar1 == 0) || (iVar2 = FUN_600f6132(iVar1), iVar2 != 4)) {
    FUN_6006ddd8(param_2,DAT_600ad8f8,0x3af);
  }
  else {
    FUN_600ad9d8(iVar1,param_2);
  }
  return;
}


