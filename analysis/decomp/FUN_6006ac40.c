// 6006ac40  FUN_6006ac40  size=106 bytes
// --- callers ---
//   6006ae20 gatt_server__6006ae20
//   6006ad00 gatt_server__6006ad00
// --- callees ---
//   6006ac00 FUN_6006ac00


undefined4 * FUN_6006ac40(undefined4 *param_1,int param_2,short param_3)

{
  undefined4 *puVar1;
  short *psVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  short local_12;
  
  local_12 = param_3;
  psVar2 = (short *)FUN_6006ac00(param_2,*(int *)(param_2 + 0xc00) * 0x30 + param_2,&local_12,
                                 DAT_6006acac,param_1);
  puVar1 = DAT_6006acb4;
  if ((((int)psVar2 - param_2 >> 4) * DAT_6006acb0 < *(int *)(param_2 + 0xc00)) &&
     (*psVar2 == local_12)) {
    uVar3 = *(undefined4 *)(psVar2 + 4);
    uVar4 = *(undefined4 *)(psVar2 + 6);
    uVar5 = *(undefined4 *)(psVar2 + 8);
    *param_1 = *(undefined4 *)(psVar2 + 2);
    param_1[1] = uVar3;
    param_1[2] = uVar4;
    param_1[3] = uVar5;
    uVar3 = *(undefined4 *)(psVar2 + 0xc);
    uVar4 = *(undefined4 *)(psVar2 + 0xe);
    uVar5 = *(undefined4 *)(psVar2 + 0x10);
    param_1[4] = *(undefined4 *)(psVar2 + 10);
    param_1[5] = uVar3;
    param_1[6] = uVar4;
    param_1[7] = uVar5;
    uVar3 = *(undefined4 *)(psVar2 + 0x14);
    uVar4 = *(undefined4 *)(psVar2 + 0x16);
    param_1[8] = *(undefined4 *)(psVar2 + 0x12);
    param_1[9] = uVar3;
    param_1[10] = uVar4;
  }
  else {
    uVar3 = DAT_6006acb4[1];
    uVar4 = DAT_6006acb4[2];
    uVar5 = DAT_6006acb4[3];
    puVar6 = DAT_6006acb4 + 4;
    *param_1 = *DAT_6006acb4;
    param_1[1] = uVar3;
    param_1[2] = uVar4;
    param_1[3] = uVar5;
    uVar3 = puVar1[5];
    uVar4 = puVar1[6];
    uVar5 = puVar1[7];
    param_1[4] = *puVar6;
    param_1[5] = uVar3;
    param_1[6] = uVar4;
    param_1[7] = uVar5;
    uVar3 = puVar1[9];
    uVar4 = puVar1[10];
    param_1[8] = puVar1[8];
    param_1[9] = uVar3;
    param_1[10] = uVar4;
  }
  return param_1;
}


