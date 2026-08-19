// 600df9c2  FUN_600df9c2  size=34 bytes
// --- callers ---
//   600df918 FUN_600df918
//   600dfa42 FUN_600dfa42
//   6008261c FUN_6008261c
// --- callees ---
//   600df918 FUN_600df918
//   600dfb00 FUN_600dfb00
//   600dfadc FUN_600dfadc


void FUN_600df9c2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  iVar1 = FUN_600dfadc(&uStack_20,param_1,param_2);
  while (iVar1 != 0) {
    FUN_600df918(&uStack_20);
    iVar1 = FUN_600dfb00(&uStack_20);
  }
  return;
}


