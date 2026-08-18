// 6009b5b4  FUN_6009b5b4  size=396 bytes
// --- callers ---
// --- callees ---
//   6009b134 FUN_6009b134
//   6009f6c0 FUN_6009f6c0
//   600f1f82 FUN_600f1f82
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6009ff18 FUN_6009ff18
//   6009b230 FUN_6009b230
//   600f9d16 FUN_600f9d16


undefined4 FUN_6009b5b4(char param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  char cVar2;
  
  iVar1 = FUN_6009ff18(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  switch(param_1) {
  case '\x01':
    FUN_6009b134(iVar1,param_3);
    break;
  case '\x03':
  case '\x04':
  case '\x05':
  case '\x06':
    *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) | 0x200;
  case '\x02':
    if ((param_1 != '\x02') || (*(char *)(DAT_6009b774 + 0x118c) == '\0')) {
      thunk_EXT_FUN_0000b572(DAT_6009b778,param_2,6);
      *(undefined1 *)(iVar1 + 0x50) = 1;
      *(byte *)(DAT_6009b774 + 0x118d) = *(byte *)(DAT_6009b774 + 0x118d) | 0x80;
      *(byte *)(iVar1 + 0xe4) = *(byte *)(iVar1 + 0xe4) | 2;
switchD_6009b5e2_caseD_7:
      if (*(int *)(DAT_6009b774 + 0x1138) != 0) {
        (**(code **)(DAT_6009b774 + 0x1138))(param_1,param_2,param_3);
      }
      if (param_1 == '\a') {
        if (*param_3 == '\0') {
          cVar2 = '\0';
        }
        else {
          cVar2 = '\n';
        }
        if ((param_3[2] != '\0') && (*(int *)(DAT_6009b774 + 0x1130) != 0)) {
          (**(code **)(DAT_6009b774 + 0x1130))(0);
        }
        if ((cVar2 != '\0') && (*param_3 != '\x19')) {
          FUN_600f9d16(*(undefined2 *)(iVar1 + 0x5e));
        }
        thunk_EXT_FUN_0000b5ba(DAT_6009b778,0xff,6);
        *(undefined1 *)(DAT_6009b774 + 0x118c) = 0;
        *(undefined1 *)(DAT_6009b774 + 0x118d) = 0;
        if (cVar2 == '\0') {
          *(byte *)(iVar1 + 0xe4) = *(byte *)(iVar1 + 0xe4) | 2;
          *(undefined1 *)(iVar1 + 0x50) = 0;
          FUN_6009f6c0(iVar1);
        }
        FUN_600f1f82(iVar1,cVar2,1);
      }
    }
    break;
  case '\a':
  case '\b':
    goto switchD_6009b5e2_caseD_7;
  default:
    break;
  case '\f':
    FUN_6009b230(iVar1,param_3);
  }
  return 0;
}


