// 600d0e58  FUN_600d0e58  size=110 bytes
// --- callers ---
//   6005505c FUN_6005505c
// --- callees ---


undefined4 FUN_600d0e58(int param_1,undefined4 param_2,ushort *param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  undefined1 uVar3;
  
  if ((param_3 == (ushort *)0x0) || (param_1 == 0)) {
    return 3;
  }
  switch(param_2) {
  case 1:
    pbVar2 = *(byte **)param_3;
    if ((*pbVar2 & 0x1f) == 1) {
      if (*(byte *)(param_1 + 0xd) == pbVar2[4]) {
                    /* WARNING: Could not recover jumptable at 0x600d0ebe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,pbVar2[1]);
        return uVar1;
      }
      return 1;
    }
    break;
  case 2:
    *(undefined1 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    break;
  case 3:
    if (*(int *)(param_1 + 4) == 0) {
      return 1;
    }
    if (*(char *)(param_1 + 0xc) == (char)*param_3) {
      return 1;
    }
    *(char *)(param_1 + 0xc) = (char)*param_3;
    uVar3 = 0;
    goto LAB_600d0e8c;
  case 4:
    if (*(int *)(param_1 + 4) == 0) {
      return 1;
    }
    uVar3 = (undefined1)*param_3;
    if ((ushort)*(byte *)(param_1 + 0xd) != *param_3 >> 8) {
      return 1;
    }
LAB_600d0e8c:
    *(undefined1 *)(param_1 + 0xe) = uVar3;
  }
  return 1;
}


