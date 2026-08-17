// 60061a98  hardware_timer__60061a98  size=188 bytes
// src: hardware_timer.cc
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   60052aa8 FUN_60052aa8
//   601016a2 FUN_601016a2
//   60053220 FUN_60053220
//   600cedc2 FUN_600cedc2
//   6005f534 FUN_6005f534
//   6010165c FUN_6010165c


/* src: hardware_timer.cc */

void hardware_timer__60061a98(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 auStack_20 [8];
  undefined1 local_18;
  
  puVar2 = DAT_60061b54;
  if ((char)param_1[8] != '\0') {
    return;
  }
  *DAT_60061b54 = (param_1[6] & 1U) << 6 | *DAT_60061b54 & 0xffffffbf;
  *puVar2 = param_1[7] & 0x3fU | *puVar2 & 0xffffffc0;
  if (*param_1 == DAT_60061b58) {
    piVar6 = DAT_60061b5c;
    if (((int *)*DAT_60061b5c != (int *)0x0) && ((int *)*DAT_60061b5c != param_1)) {
      uVar4 = 0x29;
      uVar5 = DAT_60061b60;
LAB_60061ae0:
      FUN_6010165c(0x28,DAT_60061b64,uVar4,uVar5);
    }
  }
  else {
    if (*param_1 != DAT_60061b68) {
      FUN_601016a2(DAT_60061b64,0x30,DAT_60061b74);
      goto LAB_60061aea;
    }
    piVar6 = DAT_60061b6c;
    if (((int *)*DAT_60061b6c != (int *)0x0) && ((int *)*DAT_60061b6c != param_1)) {
      uVar4 = 0x2d;
      uVar5 = DAT_60061b70;
      goto LAB_60061ae0;
    }
  }
  *piVar6 = (int)param_1;
LAB_60061aea:
  FUN_600cedc2(auStack_20);
  local_18 = 1;
  FUN_60053220(*param_1,auStack_20);
  *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) | 0x20;
  FUN_6005f534(param_1 + 1);
  iVar1 = param_1[5];
  *(uint *)*param_1 = *(uint *)*param_1 | 1;
  uVar3 = FUN_60052aa8((char)iVar1);
  *(undefined1 *)(param_1 + 8) = 1;
  param_1[10] = uVar3 / (param_1[7] + 1U);
  return;
}


