// 600c09f0  FUN_600c09f0  size=204 bytes
// --- callers ---
//   600fc602 FUN_600fc602
//   6009b77c FUN_6009b77c
//   600c1494 FUN_600c1494
//   600c12b0 FUN_600c12b0
//   600f0e98 FUN_600f0e98
//   600fc542 FUN_600fc542
//   600fc870 FUN_600fc870
// --- callees ---
//   6006dbac FUN_6006dbac
//   600c07e4 FUN_600c07e4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600c07b4 FUN_600c07b4
//   600fbcf8 FUN_600fbcf8


/* WARNING: Removing unreachable block (ram,0x600c0a0e) */

undefined1
FUN_600c09f0(undefined4 param_1,int param_2,ushort param_3,undefined2 param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  undefined1 local_b;
  short local_a;
  
  local_a = (short)((int)(param_3 + 0xf) >> 4);
  local_b = 0;
  if (local_a == 0) {
    local_a = 1;
  }
  sVar1 = local_a * 0x10;
  iVar2 = FUN_6006dbac(sVar1,DAT_600c0abc,0x128);
  *DAT_600c0ac0 = iVar2;
  if (*DAT_600c0ac0 == 0) {
    local_b = 0;
  }
  else {
    *(short *)((int)DAT_600c0ac0 + 6) = local_a;
    thunk_EXT_FUN_0000b5ba(*DAT_600c0ac0,0,sVar1);
    if ((param_2 == 0) || (param_3 == 0)) {
      *(undefined2 *)(DAT_600c0ac0 + 1) = 0;
    }
    else {
      thunk_EXT_FUN_0000b572((uint)(ushort)(sVar1 - param_3) + *DAT_600c0ac0,param_2,param_3);
      *(ushort *)(DAT_600c0ac0 + 1) = param_3;
    }
    iVar2 = FUN_600fbcf8(param_1);
    if (iVar2 != 0) {
      local_b = FUN_600c07e4(param_1,param_5,param_4);
    }
    FUN_600c07b4();
  }
  return local_b;
}


