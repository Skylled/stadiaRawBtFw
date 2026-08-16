// 600b02e0  FUN_600b02e0  size=346 bytes
// --- callers ---
//   600f5fb4 FUN_600f5fb4
//   600f5bfc FUN_600f5bfc
//   600f6042 FUN_600f6042
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f6d9c FUN_600f6d9c
//   600af170 FUN_600af170
//   600af1a4 FUN_600af1a4
//   6006ddd8 FUN_6006ddd8
//   600f610e FUN_600f610e
//   600d9250 FUN_600d9250
//   600af814 FUN_600af814
//   600b00b4 FUN_600b00b4


void FUN_600b02e0(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  byte local_11;
  
  iVar1 = FUN_600af814(param_1,param_3);
  if (iVar1 != 0) {
    FUN_600f610e(iVar1,0);
    for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
      piVar3 = (int *)(DAT_600b043c + (uint)local_11 * 0x60 + 0x1248);
      if (((char)piVar3[0x17] != '\0') && (iVar1 == *piVar3)) {
        if (*(char *)((int)piVar3 + 0x31) != '\0') {
          FUN_600b00b4(piVar3,0x85,0);
        }
        FUN_600f6d9c(piVar3);
      }
    }
    FUN_600aa3cc(iVar1 + 200);
    FUN_600aa3cc(iVar1 + 0xe0);
    FUN_600aa3cc(iVar1 + 0x74);
    FUN_600af170(iVar1);
    FUN_600af1a4(iVar1);
    while (*(int *)(iVar1 + 0x100) != 0) {
      uVar2 = FUN_600d9250(iVar1 + 0x100);
      FUN_6006ddd8(uVar2,DAT_600b0440,0x8a3);
    }
    for (local_11 = 0; local_11 < 10; local_11 = local_11 + 1) {
      iVar4 = DAT_600b043c + (uint)local_11 * 0x30 + 0x1068;
      if ((*(char *)(iVar4 + 0x2d) != '\0') && (*(int *)(iVar4 + 0x14) != 0)) {
        (**(code **)(iVar4 + 0x14))
                  (*(undefined1 *)(iVar4 + 0x2c),param_1,
                   CONCAT11(*(undefined1 *)(iVar1 + 0xfb),*(undefined1 *)(iVar4 + 0x2c)),0,param_2,
                   param_3);
      }
    }
    thunk_EXT_FUN_0000b5ba(iVar1,0,0x10c);
  }
  return;
}


