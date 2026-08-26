// 600d87f4  FUN_600d87f4  size=158 bytes
// --- callers ---
//   60068cb4 battery_gauge_bq2742X__60068cb4
// --- callees ---
//   600d8778 FUN_600d8778
//   600d83e0 FUN_600d83e0
//   60068ae0 battery_gauge_bq2742X__60068ae0
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   600d8722 FUN_600d8722


uint FUN_600d87f4(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar7;
  int iVar8;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined4 auStack_3b [8];
  undefined4 *puVar6;
  
  FUN_600d8778();
  iVar4 = param_1[4];
  iVar8 = param_1[5];
  puVar7 = (undefined4 *)(iVar4 + 3);
  while( true ) {
    if (puVar7 == (undefined4 *)(iVar8 * 0x23 + iVar4 + 3)) {
      FUN_600d8722(param_1);
      return 0;
    }
    local_3d = 0;
    uVar2 = FUN_600d83e0(param_1,*(undefined1 *)((int)puVar7 + -3),*(undefined1 *)((int)puVar7 + -2)
                         ,&local_3d);
    if ((uVar2 & 0xff) != 0) break;
    local_3c = 0x40;
    puVar3 = auStack_3b;
    puVar5 = puVar7;
    do {
      puVar6 = puVar5 + 1;
      *puVar3 = *puVar5;
      puVar3 = puVar3 + 1;
      puVar5 = puVar6;
    } while (puVar6 != puVar7 + 8);
    bVar1 = thunk_EXT_FUN_00001ea4(*param_1,*(undefined1 *)(param_1 + 1),&local_3c,0x21,0,0,200);
    if (bVar1 != 0) {
      return (uint)bVar1;
    }
    uVar2 = battery_gauge_bq2742X__60068ae0
                      (param_1,*(undefined1 *)((int)puVar7 + -1),*(undefined1 *)((int)puVar7 + -3),
                       *(undefined1 *)((int)puVar7 + -2));
    puVar7 = (undefined4 *)((int)puVar7 + 0x23);
    if ((uVar2 & 0xff) != 0) {
      return uVar2;
    }
  }
  return uVar2;
}


