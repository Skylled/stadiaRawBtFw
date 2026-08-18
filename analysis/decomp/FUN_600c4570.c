// 600c4570  FUN_600c4570  size=246 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   601024d8 FUN_601024d8
//   600f1800 FUN_600f1800


undefined4 FUN_600c4570(undefined4 param_1,undefined1 *param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_120 [6];
  undefined1 uStack_11a;
  undefined1 uStack_119;
  undefined1 uStack_118;
  undefined1 auStack_117 [248];
  undefined1 uStack_1f;
  
  if (*(int *)(DAT_600c4668 + 0xe8) == 0) {
    uVar2 = 0xb;
  }
  else {
    if (*param_3 == '\0') {
      *(undefined1 *)(DAT_600c4668 + 0x27d) = 2;
      FUN_600efcc6(DAT_600c466c,param_1);
      *(undefined1 *)(DAT_600c4668 + 0x27a) = *param_2;
      *(undefined1 *)(DAT_600c4668 + 0x27b) = param_2[1];
      *(undefined1 *)(DAT_600c4668 + 0x27c) = param_2[2];
      iVar1 = FUN_600f1800(param_1,DAT_600c4670,1);
      if (iVar1 == 1) {
        return 1;
      }
    }
    FUN_600efcc6(auStack_120,param_1);
    uStack_11a = *param_2;
    uStack_119 = param_2[1];
    uStack_118 = param_2[2];
    FUN_601024d8(auStack_117,param_3,0xf8);
    uStack_1f = 0;
    (**(code **)(DAT_600c4668 + 0xe8))(2,auStack_120);
    uVar2 = 1;
  }
  return uVar2;
}


