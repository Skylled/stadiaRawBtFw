// 600a3904  FUN_600a3904  size=304 bytes
// --- callers ---
//   600a3a38 FUN_600a3a38
// --- callees ---
//   600a3784 FUN_600a3784


undefined1 FUN_600a3904(char param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined4 *local_14;
  int local_10;
  int local_c;
  
  local_14 = (undefined4 *)0x0;
  if ((param_3 == (undefined4 *)0x0) || ((*(byte *)(param_3 + 2) & 0x10) == 0)) {
    if (param_3 == (undefined4 *)0x0) {
      local_10 = 2;
    }
    else {
      local_10 = 1;
    }
    for (local_c = 0; local_c < local_10; local_c = local_c + 1) {
      if ((*(byte *)((local_c + 0xdb) * 8 + DAT_600a3a34 + 8) & 1) != 0) {
        if (local_c == 1) {
          *(byte *)(DAT_600a3a34 + 0x6e8) = *(byte *)(DAT_600a3a34 + 0x6e8) & 0xfe;
        }
        if (*(char *)(local_c * 10 + param_2 + 8) == '\0') {
          return 0;
        }
        iVar1 = FUN_600a3784(local_14,local_c * 10 + param_2,param_4);
        local_14 = param_4;
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    if (local_14 == (undefined4 *)0x0) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      uVar2 = param_3[1];
      *param_4 = *param_3;
      param_4[1] = uVar2;
      *(undefined2 *)(param_4 + 2) = *(undefined2 *)(param_3 + 2);
    }
    else if ((param_1 == -0x80) && (iVar1 = FUN_600a3784(param_3,local_14,param_4), iVar1 == 0)) {
      return 0;
    }
    uVar3 = *(undefined1 *)(param_4 + 2);
  }
  else {
    uVar2 = param_3[1];
    *param_4 = *param_3;
    param_4[1] = uVar2;
    *(undefined2 *)(param_4 + 2) = *(undefined2 *)(param_3 + 2);
    *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0xef;
    uVar3 = *(undefined1 *)(param_4 + 2);
  }
  return uVar3;
}


