// 600d6074  FUN_600d6074  size=140 bytes
// --- callers ---
//   600d6100 FUN_600d6100
//   600d6074 FUN_600d6074
// --- callees ---
//   600d5c6a FUN_600d5c6a
//   600d6074 FUN_600d6074
//   60063dec FUN_60063dec
//   600d6028 FUN_600d6028
//   60063c58 FUN_60063c58
//   600d5c16 FUN_600d5c16


void FUN_600d6074(int param_1,undefined3 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&stack0xffffffe7,param_3,param_4,param_1,
                       CONCAT13((char)param_2,param_2));
  iVar4 = *(int *)(param_1 + 0x54);
  if (iVar4 + 4 == iVar1) {
    return;
  }
  iVar1 = FUN_60063dec(iVar4,&stack0xffffffe7);
  if (*(char *)(iVar1 + 6) != '\0') {
    return;
  }
  *(undefined1 *)(iVar1 + 6) = 1;
  if (param_4 == 0) {
    FUN_60063dec(iVar4,&stack0xffffffe7);
    iVar1 = FUN_600d5c16();
    if (iVar1 != 0) {
LAB_600d60b4:
      FUN_60063c58(param_3,&stack0xffffffe7);
      return;
    }
  }
  else if (param_4 == 1) {
    iVar1 = FUN_60063dec(iVar4,&stack0xffffffe7);
    iVar4 = FUN_600d5c6a();
    if (iVar4 != 0) goto LAB_600d60b4;
    puVar2 = (undefined4 *)(iVar1 + 8);
    goto LAB_600d60dc;
  }
  iVar1 = FUN_60063dec(iVar4,&stack0xffffffe7);
  puVar2 = (undefined4 *)(iVar1 + 0x14);
LAB_600d60dc:
  puVar5 = (undefined1 *)puVar2[1];
  for (puVar3 = (undefined1 *)*puVar2; puVar3 != puVar5; puVar3 = puVar3 + 1) {
    FUN_600d6074(param_1,*puVar3,param_3,param_4);
  }
  return;
}


