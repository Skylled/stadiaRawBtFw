// 600a3424  FUN_600a3424  size=436 bytes
// --- callers ---
//   600b5ec8 FUN_600b5ec8
//   600942d4 FUN_600942d4
//   60094208 FUN_60094208
//   600b6d30 FUN_600b6d30
//   600941c4 FUN_600941c4
//   6009931c FUN_6009931c
// --- callees ---
//   600a3724 FUN_600a3724
//   600a1354 FUN_600a1354
//   600a3a38 FUN_600a3a38


undefined4 FUN_600a3424(byte param_1,undefined4 param_2,ushort *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  byte local_21;
  uint local_c;
  
  local_21 = param_1;
  if (param_1 != 0) {
    local_21 = 0x80;
  }
  if (param_3 == (ushort *)0x0) {
    return 5;
  }
  bVar4 = (byte)param_3[4] & 0xef;
  uVar1 = FUN_600a3724(param_2);
  if (uVar1 == 4) {
    return 7;
  }
  iVar5 = uVar1 * 0x24 + DAT_600a35d8;
  if ((bVar4 != 0) &&
     (iVar2 = FUN_600a1354(),
     (*(byte *)((bVar4 - 1) + DAT_600a35e0) &
     *(byte *)(iVar2 + (uint)*(byte *)((bVar4 - 1) + DAT_600a35dc))) == 0)) {
    return 4;
  }
  if ((bVar4 == *(byte *)(iVar5 + 0x66c)) &&
     (((bVar4 == 0 ||
       ((((param_3[4] & 0x10) != 0 && (*(ushort *)(iVar5 + 0x66a) <= *param_3)) &&
        (param_3[1] <= *(ushort *)(iVar5 + 0x66a))))) ||
      (((param_3[4] & 0x10) == 0 && (*(ushort *)(iVar5 + 0x66a) <= *param_3)))))) {
    return 0;
  }
  local_c = (uint)local_21;
  if (local_21 == 0x80) {
    local_c = 1;
LAB_600a352c:
    if ((local_21 != 0x80) || (*(char *)(DAT_600a35d8 + 0x6ec) == '\x04')) goto LAB_600a3580;
  }
  else if ((*(byte *)((local_21 + 0xdb) * 8 + DAT_600a35d8 + 8) & 1) == 0) goto LAB_600a352c;
  *(byte *)((local_c + 0xdb) * 8 + DAT_600a35d8 + 8) =
       *(byte *)((local_c + 0xdb) * 8 + DAT_600a35d8 + 8) | 1;
  puVar6 = (undefined4 *)(local_c * 10 + iVar5 + 0x64c);
  uVar3 = *(undefined4 *)(param_3 + 2);
  *puVar6 = *(undefined4 *)param_3;
  puVar6[1] = uVar3;
  *(ushort *)(puVar6 + 2) = param_3[4];
  *(undefined1 *)(iVar5 + 0x66e) = 1;
LAB_600a3580:
  if (((*(char *)(iVar5 + 0x66c) == '\x01') || (*(char *)(iVar5 + 0x66c) == '\x05')) ||
     (*(char *)(DAT_600a35d8 + 0x6ec) != '\x04')) {
    if (uVar1 != *(byte *)(DAT_600a35d8 + 0x6ec)) {
      *(byte *)(iVar5 + 0x66c) = *(byte *)(iVar5 + 0x66c) | 0x80;
    }
    uVar3 = 0xd;
  }
  else {
    uVar3 = FUN_600a3a38(local_21,uVar1,param_3);
  }
  return uVar3;
}


