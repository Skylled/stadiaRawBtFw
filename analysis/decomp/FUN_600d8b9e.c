// 600d8b9e  FUN_600d8b9e  size=76 bytes
// --- callers ---
//   6006ad00 gatt_server__6006ad00
//   6006a634 gatt_server__6006a634
//   6006ae20 gatt_server__6006ae20
// --- callees ---
//   600d8a62 FUN_600d8a62


undefined4 FUN_600d8b9e(ushort *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x100);
  iVar5 = (iVar6 << 3) >> 3;
  puVar4 = param_1;
  while (iVar3 = iVar5, 0 < iVar3) {
    iVar5 = iVar3 >> 1;
    iVar1 = FUN_600d8a62(puVar4 + iVar5 * 4,param_2);
    if (iVar1 != 0) {
      puVar4 = puVar4 + iVar5 * 4 + 4;
      iVar5 = (iVar3 - iVar5) + -1;
    }
  }
  if (((int)puVar4 - (int)param_1 >> 3 < iVar6) && (*puVar4 == param_2)) {
    uVar2 = *(undefined4 *)(puVar4 + 2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


