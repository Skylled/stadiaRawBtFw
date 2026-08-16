// 6009c444  FUN_6009c444  size=334 bytes
// --- callers ---
//   6009c9d4 FUN_6009c9d4
//   6009c6d8 FUN_6009c6d8
//   600f1334 FUN_600f1334
//   6009c71c FUN_6009c71c
// --- callees ---
//   6009c790 FUN_6009c790
//   6009f990 FUN_6009f990
//   6009eb9c FUN_6009eb9c
//   600b0fc8 FUN_600b0fc8
//   600b0e2c FUN_600b0e2c
//   6009c01c FUN_6009c01c
//   6009c240 FUN_6009c240


undefined1 FUN_6009c444(char param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_14;
  undefined2 local_12;
  int local_10;
  byte local_b;
  byte local_a;
  undefined1 local_9;
  
  local_10 = DAT_6009c594;
  local_1c = 0;
  local_18 = 0;
  local_9 = 1;
  local_a = *(byte *)(DAT_6009c594 + 0x164);
  local_b = 0;
  if (param_1 == '\0') {
    if (*(char *)(DAT_6009c594 + 0x160) == '\x02') {
      FUN_600b0fc8();
      FUN_6009c790(3);
      *(byte *)(local_10 + 0xf6) = *(byte *)(local_10 + 0xf6) & 0xfe;
    }
    else {
      local_9 = 0;
    }
  }
  else if (((*(char *)(DAT_6009c594 + 0x160) == '\0') && (iVar1 = FUN_6009c240(), iVar1 != 0)) &&
          (iVar1 = FUN_6009eb9c(2), iVar1 != 0)) {
    *(byte *)(local_10 + 0xf6) = *(byte *)(local_10 + 0xf6) | 1;
    FUN_6009c01c();
    FUN_6009f990(1);
    if (*(short *)(local_10 + 0xea) == -1) {
      local_12 = 0x800;
    }
    else {
      local_12 = *(undefined2 *)(local_10 + 0xea);
    }
    if (*(short *)(local_10 + 0xec) == -1) {
      local_14 = 0x12;
    }
    else {
      local_14 = *(undefined2 *)(local_10 + 0xec);
    }
    if (*(char *)(DAT_6009c598 + 0xa80) != '\0') {
      local_a = local_a | 2;
      local_b = local_b | 2;
    }
    iVar1 = FUN_600b0e2c(local_12,local_14,1,local_b,&local_1c,local_a,0x18,0x28,0,2000,0,0);
    if (iVar1 == 0) {
      local_9 = 0;
      *(byte *)(local_10 + 0xf6) = *(byte *)(local_10 + 0xf6) & 0xfe;
    }
    else {
      FUN_6009c790(2);
    }
  }
  else {
    local_9 = 0;
  }
  return local_9;
}


