// 6009c914  FUN_6009c914  size=176 bytes
// --- callers ---
//   600fd3a4 FUN_600fd3a4
// --- callees ---
//   600aad90 FUN_600aad90
//   600f0f26 FUN_600f0f26


undefined4 FUN_6009c914(char param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 local_d;
  int local_c;
  
  iVar1 = DAT_6009c9c4;
  local_c = DAT_6009c9c4;
  local_d = 0;
  if ((*(byte *)(DAT_6009c9c8 + 0x81b) & 2) == 0) {
    uVar3 = 4;
  }
  else {
    if (param_1 == '\0') {
      *(undefined1 *)(DAT_6009c9c4 + 0x164) = 0;
      *(undefined1 *)(iVar1 + 0x19a) = 0;
    }
    else {
      *(undefined1 *)(DAT_6009c9c4 + 0x164) = 1;
      FUN_600f0f26(DAT_6009c9cc);
      if (*(int *)(DAT_6009c9d0 + 0xd4) != 0) {
        (**(code **)(DAT_6009c9d0 + 0xd4))(0x12,local_c + 0x19a);
      }
      if ((*(byte *)(DAT_6009c9c8 + 0x831) & 0x40) == 0) {
        *(undefined1 *)(local_c + 0x19a) = 1;
      }
      else {
        local_d = 1;
        if (*(char *)(DAT_6009c9c8 + 0xa69) == '\0') {
          uVar2 = 2;
        }
        else {
          uVar2 = 3;
        }
        *(undefined1 *)(local_c + 0x19a) = uVar2;
      }
    }
    FUN_600aad90(0x2aa6,&local_d);
    uVar3 = 0;
  }
  return uVar3;
}


