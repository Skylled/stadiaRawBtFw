// 600de582  FUN_600de582  size=244 bytes
// --- callers ---
// --- callees ---


void FUN_600de582(char *param_1,int param_2,int param_3,int param_4,char param_5,char param_6,
                 byte param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  uVar2 = *(int *)(param_1 + 4) + 1;
  *(uint *)(param_1 + 4) = uVar2;
  if (param_6 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = param_7 ^ 1;
  }
  *(uint *)(param_1 + 0x28) = uVar3 + *(int *)(param_1 + 0x28);
  if ((param_3 == 0) || (4 < param_2)) {
    if (param_6 == '\0') goto LAB_600de5b6;
    iVar1 = *(int *)(param_1 + 0xc) + 1;
  }
  else {
    param_1[0x10] = '\x01';
    iVar1 = 0;
  }
  *(int *)(param_1 + 0xc) = iVar1;
LAB_600de5b6:
  if (param_1[0x10] == '\0') {
    bVar5 = 0x4e1 < uVar2;
    bVar4 = uVar2 == 0x4e2;
  }
  else {
    bVar5 = 0x1d4b < *(uint *)(param_1 + 0xc);
    bVar4 = *(uint *)(param_1 + 0xc) == 0x1d4c;
  }
  if (param_4 == 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(uint *)(param_1 + 0x14) = iVar1 + 1U;
    if (5000 < iVar1 + 1U) {
      param_1[0x20] = '\0';
      param_1[0x21] = '\0';
      param_1[0x22] = '\0';
      param_1[0x23] = '\0';
    }
    if ((param_6 != '\0') &&
       (iVar1 = *(int *)(param_1 + 0x1c), *(uint *)(param_1 + 0x1c) = iVar1 + 1U, 15000 < iVar1 + 1U
       )) {
      param_1[0x24] = '\0';
    }
  }
  else {
    param_1[0x24] = '\x01';
    param_1[0x1c] = '\0';
    param_1[0x1d] = '\0';
    param_1[0x1e] = '\0';
    param_1[0x1f] = '\0';
    param_1[0x14] = '\0';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  if (param_5 == '\0') {
    param_1[0x18] = '\0';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
  }
  else {
    iVar1 = *(int *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = iVar1 + 1U;
    if (0x3b < iVar1 + 1U) {
      param_1[0x14] = '\x10';
      param_1[0x15] = '\'';
      param_1[0x16] = '\0';
      param_1[0x17] = '\0';
    }
  }
  if (15000 < *(uint *)(param_1 + 0x1c)) {
    param_1[0x11] = '\0';
  }
  if (0x32 < *(uint *)(param_1 + 0x20)) {
    param_1[0x11] = '\x01';
  }
  if (((*param_1 != '\0') || (param_1[0x11] != '\0')) ||
     ((!bVar5 || bVar4 && (param_1[0x24] != '\0')))) {
    bVar4 = false;
  }
  else {
    bVar4 = 0x5dc < *(uint *)(param_1 + 0x28);
  }
  param_1[8] = bVar4;
  return;
}


