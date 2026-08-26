// 600d5e6c  FUN_600d5e6c  size=122 bytes
// --- callers ---
//   600641a8 usb_host_audio_topology__600641a8
// --- callees ---
//   600d5bd2 FUN_600d5bd2


undefined4 * FUN_600d5e6c(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 *puVar8;
  
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  cVar2 = *(char *)(param_2 + 4);
  if (cVar2 != '\0') {
    uVar4 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = uVar4;
  }
  *(bool *)(param_1 + 4) = cVar2 != '\0';
  iVar5 = param_2[5];
  iVar7 = param_2[6];
  param_1[7] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  iVar3 = 0;
  if (iVar7 - iVar5 >> 1 != 0) {
    iVar3 = FUN_600d5bd2();
  }
  param_1[5] = iVar3;
  param_1[6] = iVar3;
  param_1[7] = (iVar7 - iVar5) + iVar3;
  iVar5 = param_2[5];
  puVar6 = (undefined2 *)param_2[6];
  for (iVar7 = 0; puVar8 = (undefined2 *)(iVar7 + iVar5), puVar6 != puVar8; iVar7 = iVar7 + 2) {
    *(undefined2 *)(iVar3 + iVar7) = *puVar8;
  }
  cVar2 = *(char *)((int)param_2 + 0x23);
  param_1[6] = (int)puVar6 + (iVar3 - iVar5);
  bVar1 = cVar2 != '\0';
  if (bVar1) {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
    *(undefined1 *)((int)param_1 + 0x22) = *(undefined1 *)((int)param_2 + 0x22);
  }
  *(bool *)((int)param_1 + 0x23) = bVar1;
  return param_1;
}


