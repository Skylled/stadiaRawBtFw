// 6009e4d0  FUN_6009e4d0  size=482 bytes
// --- callers ---
//   6009e3f0 FUN_6009e3f0
//   600f13d8 FUN_600f13d8
// --- callees ---
//   600a26ec FUN_600a26ec
//   6009e098 FUN_6009e098
//   600a2640 FUN_600a2640
//   6009e1b4 FUN_6009e1b4
//   600b1ef8 FUN_600b1ef8
//   6009e338 FUN_6009e338
//   600a2740 FUN_600a2740
//   6009e70c FUN_6009e70c


void FUN_6009e4d0(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  byte local_e;
  char local_d;
  int local_c;
  
  iVar2 = DAT_6009e6bc;
  iVar1 = DAT_6009e6b4;
  pcVar4 = *(code **)(DAT_6009e6b4 + 0x38);
  pcVar5 = *(code **)(DAT_6009e6b8 + 0x998);
  local_d = '\x01';
  local_c = FUN_600a26ec(param_1);
  iVar3 = FUN_600a2640(param_1);
  if (iVar3 != 0) {
    if ((local_c == 0) ||
       (((*(byte *)(local_c + 0x17) & 2) != 0 && (*(char *)(local_c + 0x2f) != '\0')))) {
      if (-1 < *(char *)(DAT_6009e6b8 + 0x8d0)) {
        return;
      }
      local_d = '\0';
    }
    else {
      local_d = '\x01';
    }
  }
  if ((((local_c != 0) || (local_c = FUN_600a2740(param_1), local_c != 0)) &&
      (iVar3 = FUN_6009e1b4(local_c,param_2,param_3,param_4,local_d), iVar3 != 0)) &&
     (local_e = FUN_6009e098(param_1,param_3,param_4), local_e != 0)) {
    if (*(int *)(local_c + 4) != *(int *)(iVar1 + 0x44)) {
      *(undefined4 *)(local_c + 4) = *(undefined4 *)(iVar1 + 0x44);
      *(char *)(iVar1 + 0x614) = *(char *)(iVar1 + 0x614) + '\x01';
    }
    if (local_d == '\0') {
      local_e = local_e & 0xfe;
    }
    if (((*(char *)(iVar1 + 0x60a) != '\0') &&
        (*(char *)(iVar1 + 0x614) == *(char *)(iVar1 + 0x60a))) &&
       ((local_c == 0 ||
        (((local_c != 0 && (*(char *)(local_c + 0x17) == '\x02')) &&
         (*(char *)(local_c + 0x2f) != '\0')))))) {
      if (((*(byte *)(iVar1 + 0x61e) & 0xb) != 0) && ((*(byte *)(iVar1 + 0x61e) & 8) == 0)) {
        FUN_600b1ef8();
      }
      FUN_6009e70c();
    }
    if (*(char *)(DAT_6009e6b8 + 0x9b8) == '\x02') {
      if ((local_e & 4) != 0) {
        FUN_6009e338(param_1,param_3,param_4,param_2);
      }
    }
    else {
      if ((pcVar4 != (code *)0x0) && ((local_e & 1) != 0)) {
        (*pcVar4)(local_c + 8,iVar2 + 0x35);
      }
      if ((pcVar5 != (code *)0x0) && ((local_e & 2) != 0)) {
        (*pcVar5)(local_c + 8,iVar2 + 0x35);
      }
    }
  }
  return;
}


