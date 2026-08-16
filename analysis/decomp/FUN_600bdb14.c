// 600bdb14  FUN_600bdb14  size=98 bytes
// --- callers ---
//   600f6c4c FUN_600f6c4c
// --- callees ---
//   600bd848 FUN_600bd848
//   6006ddd8 FUN_6006ddd8
//   600fa440 FUN_600fa440
//   6006dbac FUN_6006dbac


undefined1 FUN_600bdb14(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_6006dbac(0x200,DAT_600bdb78,0x299);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar3 = FUN_600fa440(iVar2,param_2,param_3);
    uVar1 = FUN_600bd848(param_1,4,6,uVar3,iVar2);
    FUN_6006ddd8(iVar2,DAT_600bdb78,0x2a1);
  }
  return uVar1;
}


