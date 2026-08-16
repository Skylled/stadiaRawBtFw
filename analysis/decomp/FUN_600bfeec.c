// 600bfeec  FUN_600bfeec  size=148 bytes
// --- callers ---
//   600beb20 FUN_600beb20
//   600be558 FUN_600be558
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006ddd8 FUN_6006ddd8
//   600bf3b4 FUN_600bf3b4
//   600bfe2c FUN_600bfe2c
//   6006dbac FUN_6006dbac


int FUN_600bfeec(int param_1,undefined4 param_2,ushort param_3,ushort *param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_6006dbac(0x100,DAT_600bff80,0x3e9);
  if (iVar2 == 0) {
    param_1 = 0;
  }
  else {
    FUN_600bf3b4(iVar2,param_2);
    uVar1 = FUN_600bfe2c(param_2);
    uVar3 = (uint)uVar1 - (uint)*param_4;
    if ((int)(uint)param_3 <= (int)((uint)uVar1 - (uint)*param_4)) {
      uVar3 = (uint)param_3;
    }
    thunk_EXT_FUN_0000b572(param_1,iVar2 + (uint)*param_4,uVar3);
    param_1 = uVar3 + param_1;
    *param_4 = (short)uVar3 + *param_4;
    FUN_6006ddd8(iVar2,DAT_600bff80,0x3fa);
  }
  return param_1;
}


