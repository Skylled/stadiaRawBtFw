// 600f32aa  FUN_600f32aa  size=110 bytes
// --- callers ---
//   600f3318 FUN_600f3318
//   600f3378 FUN_600f3378
// --- callees ---
//   600f322e FUN_600f322e
//   600aa800 FUN_600aa800
//   600f3da6 FUN_600f3da6


void FUN_600f32aa(int param_1,undefined1 param_2,undefined2 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(param_1 + 8);
  sVar1 = *(short *)(param_1 + 0xe);
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if ((pcVar3 != (code *)0x0) && (sVar1 != 0)) {
    (*pcVar3)(param_2,param_1,param_3,param_4);
  }
  if ((*(char *)(param_1 + 0x11) != '\0') && (iVar2 = FUN_600f322e(param_1), iVar2 == 0)) {
    FUN_600f3da6(*(undefined2 *)(param_1 + 0xc));
    FUN_600aa800(param_1);
  }
  return;
}


