// 600d80f4  FUN_600d80f4  size=260 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d4752 FUN_600d4752
//   60067f20 FUN_60067f20
//   600d8052 FUN_600d8052
//   6013d168 thunk_EXT_FUN_0000b554
//   600d80d0 FUN_600d80d0


uint FUN_600d80f4(int param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  char acStack_38 [16];
  char acStack_28 [4];
  
  if ((((param_4 == (undefined1 *)0x0) ||
       (uVar2 = (uint)*(byte *)(param_1 + 0x18), uVar2 * (0x10 / uVar2) != 0x10)) ||
      (param_2 != uVar2 * (param_2 / uVar2))) || (param_3 != uVar2 * (param_3 / uVar2))) {
    uVar2 = 3;
  }
  else {
    thunk_EXT_FUN_0000b5ba(auStack_48,0xff);
    uVar3 = FUN_600d4752(param_1,param_2);
    FUN_60067f20(acStack_38);
    uVar2 = FUN_600d80d0(acStack_38 + 0xc,uVar3);
    if ((uVar2 & 0xff) == 0) {
      iVar5 = *(int *)(param_1 + 0x20);
      *param_4 = (char)uVar2;
      pcVar7 = acStack_38;
      if (iVar5 != 2) {
        pcVar7 = (char *)0x0;
      }
LAB_600d816c:
      if (param_3 != 0) {
        uVar2 = param_3;
        if (0xf < param_3) {
          uVar2 = 0x10;
        }
        uVar4 = FUN_600d8052(param_1,auStack_58,param_2,uVar2);
        if ((uVar4 & 0xff) != 0) {
          return uVar4;
        }
        uVar4 = (**(code **)(**(int **)(param_1 + 0x14) + 8))
                          (*(int **)(param_1 + 0x14),auStack_58,auStack_58,0x10,pcVar7,
                           *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));
        if ((uVar4 & 0xff) != 0) {
          return uVar4;
        }
        iVar5 = thunk_EXT_FUN_0000b554(auStack_58,auStack_48,uVar2);
        if (iVar5 != 0) {
          return 0;
        }
        param_2 = param_2 + uVar2;
        param_3 = param_3 - uVar2;
        if (((*(int *)(param_1 + 0x20) == 2) && ((uVar2 & 0xf) == 0)) && (uVar2 >> 4 != 0)) {
          pcVar6 = acStack_28;
          do {
            pcVar6 = pcVar6 + -1;
            cVar1 = *pcVar6;
            *pcVar6 = cVar1 + '\x01';
            if ((char)(cVar1 + '\x01') != '\0') break;
          } while (acStack_38 != pcVar6);
        }
        goto LAB_600d816c;
      }
      *param_4 = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


