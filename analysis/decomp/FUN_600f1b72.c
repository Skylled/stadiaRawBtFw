// 600f1b72  FUN_600f1b72  size=370 bytes
// --- callers ---
//   600a5760 FUN_600a5760
//   600c5670 FUN_600c5670
//   600ac438 FUN_600ac438
// --- callees ---
//   6009ff18 FUN_6009ff18
//   600f0bb8 FUN_600f0bb8
//   600a8228 FUN_600a8228
//   600a7b44 FUN_600a7b44
//   60098ec8 FUN_60098ec8


char FUN_600f1b72(undefined4 param_1,char param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  char local_11;
  
  iVar1 = FUN_60098ec8(param_1,param_2);
  iVar2 = FUN_6009ff18(param_1);
  if (((iVar2 == 0) || ((param_2 == '\x01' && (*(short *)(iVar2 + 0xc) == -1)))) ||
     ((param_2 == '\x02' && (*(short *)(iVar2 + 0x5e) == -1)))) {
    if (param_3 != (code *)0x0) {
      (*param_3)(param_1,param_2,param_4,6);
    }
    local_11 = '\x06';
  }
  else if (((param_2 == '\x01') && ((*(ushort *)(iVar2 + 0x2a) & 6) == 6)) ||
          ((param_2 == '\x02' && ((*(ushort *)(iVar2 + 0x2a) & 0x600) == 0x600)))) {
    if (param_3 != (code *)0x0) {
      (*param_3)(param_1,param_2,param_4,0);
    }
    local_11 = '\0';
  }
  else if ((*(int *)(iVar2 + 0xf4) == 0) && (*(char *)(iVar2 + 0x50) == '\0')) {
    *(code **)(iVar2 + 0xf4) = param_3;
    *(undefined4 *)(iVar2 + 0xf8) = param_4;
    *(ushort *)(iVar2 + 0x54) = *(ushort *)(iVar2 + 0x54) | 6;
    *(undefined1 *)(iVar2 + 0x51) = 0;
    if (param_2 == '\x02') {
      if (iVar1 == 0) {
        local_11 = '\x06';
      }
      else {
        local_11 = FUN_600f0bb8(param_1,param_4,*(undefined1 *)(iVar1 + 0x129));
      }
    }
    else {
      local_11 = FUN_600a7b44(iVar2);
    }
    if (((local_11 != '\x01') && (local_11 != '\x02')) && (param_3 != (code *)0x0)) {
      *(undefined4 *)(iVar2 + 0xf4) = 0;
      (*param_3)(param_1,param_2,*(undefined4 *)(iVar2 + 0xf8),local_11);
    }
  }
  else {
    iVar1 = FUN_600a8228(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      if (param_3 != (code *)0x0) {
        (*param_3)(param_1,param_2,param_4,3);
      }
      local_11 = '\x03';
    }
    else {
      local_11 = '\x01';
    }
  }
  return local_11;
}


