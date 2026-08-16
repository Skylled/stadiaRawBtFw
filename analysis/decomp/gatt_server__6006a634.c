// 6006a634  gatt_server__6006a634  size=244 bytes
// src: gatt_server.h
// --- callers ---
//   6006a9c8 gatt_server__6006a9c8
// --- callees ---
//   6010165c FUN_6010165c
//   60051120 FUN_60051120
//   600d8a62 FUN_600d8a62
//   600d37ac FUN_600d37ac
//   600d37b8 FUN_600d37b8
//   600d8b9e FUN_600d8b9e


/* src: gatt_server.h */

undefined1 gatt_server__6006a634(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  undefined1 auStack_c4 [8];
  undefined1 auStack_bc [144];
  undefined1 local_2c;
  
  puVar6 = (ushort *)(param_1 + 0x28);
  iVar1 = FUN_600d8b9e(puVar6,param_3);
  if (iVar1 != 0) {
    FUN_6010165c(0x1e,DAT_6006a72c,0x4e,DAT_6006a728,param_3);
  }
  iVar7 = *(int *)(param_1 + 0x228);
  puVar5 = puVar6;
  iVar1 = iVar7 * 8 >> 3;
  while (iVar4 = iVar1, 0 < iVar4) {
    iVar1 = iVar4 >> 1;
    iVar2 = FUN_600d8a62(puVar5 + iVar1 * 4,param_3);
    if (iVar2 != 0) {
      puVar5 = puVar5 + iVar1 * 4 + 4;
      iVar1 = (iVar4 - iVar1) + -1;
    }
  }
  if (((int)puVar5 - (int)puVar6 >> 3 < iVar7) && (*puVar5 == param_3)) {
    *(int *)(puVar5 + 2) = param_2;
  }
  else {
    if (0x40 < iVar7 + 1U) {
      FUN_60051120(auStack_c4,DAT_6006a72c,0x4f,8);
      FUN_600d37ac(auStack_bc,DAT_6006a730);
      FUN_600d37b8(auStack_c4);
      return local_2c;
    }
    iVar4 = (int)puVar6 + (iVar7 * 8 - (int)puVar5) >> 3;
    iVar1 = iVar4;
    while (iVar2 = iVar1 + -1, 0 < iVar1) {
      uVar3 = *(undefined4 *)(puVar6 + iVar7 * 4 + iVar4 * -4 + iVar2 * 4 + 2);
      *(undefined4 *)(puVar6 + iVar4 * -4 + iVar7 * 4 + iVar2 * 4 + 4) =
           *(undefined4 *)(puVar6 + iVar7 * 4 + iVar4 * -4 + iVar2 * 4);
      *(undefined4 *)(puVar6 + iVar4 * -4 + iVar7 * 4 + iVar2 * 4 + 4 + 2) = uVar3;
      iVar1 = iVar2;
    }
    *puVar5 = (ushort)param_3;
    *(int *)(puVar5 + 2) = param_2;
    *(uint *)(param_1 + 0x228) = iVar7 + 1U;
  }
  *(ushort *)(param_2 + 8) = (ushort)param_3;
  return 0;
}


