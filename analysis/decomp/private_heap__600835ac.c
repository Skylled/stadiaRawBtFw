// 600d15c4  private_heap__600835ac  size=4 bytes
// --- callers ---
//   600d6956 FUN_600d6956
//   600649d4 usb_host_hid__600649d4
//   600d234e FUN_600d234e
//   600d6946 FUN_600d6946
//   600d25f4 FUN_600d25f4
//   600567fc FUN_600567fc
// --- callees ---


void private_heap__600835ac(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 != 0) {
    iVar5 = param_1 + -0x10;
    private_heap__60083568(iVar5);
    *(undefined4 *)(param_1 + -8) = 0x10;
    uVar1 = FUN_600dfd6a(iVar5);
    *(undefined4 *)(param_1 + -4) = uVar1;
    if (*(int *)(param_1 + -0x10) != -1) {
      uVar6 = FUN_600dfd6a(iVar5,uVar1);
      if ((int)((ulonglong)uVar6 >> 0x20) != (int)uVar6) {
        FUN_601016a2(DAT_60083674,0x31,DAT_60083670);
      }
      iVar3 = iVar5 - *(int *)(param_1 + -0x10);
      iVar4 = iVar3 + -0x10;
      if (((iVar4 != 0) && (*(int *)(iVar3 + -8) == 0x10)) && (*(int *)(iVar3 + -0xc) != -1)) {
        *(int *)(iVar3 + -0xc) = *(int *)(param_1 + -0xc) + 0x10 + *(int *)(iVar3 + -0xc);
        uVar1 = FUN_600dfd6a(iVar4);
        *(undefined4 *)(iVar3 + -4) = uVar1;
        *(undefined4 *)(param_1 + -8) = 0xff;
        puVar2 = (undefined4 *)private_heap__60083534(iVar4);
        iVar5 = iVar4;
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *(undefined4 *)(iVar3 + -0xc);
          uVar6 = FUN_600dfd6a(puVar2,puVar2);
          *(int *)((int)((ulonglong)uVar6 >> 0x20) + 0xc) = (int)uVar6;
        }
      }
    }
    iVar3 = private_heap__60083534(iVar5);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 8) == 0x10)) && (*(int *)(iVar3 + 4) != -1)) {
      *(undefined4 *)(iVar3 + 8) = 0xff;
      *(int *)(iVar5 + 4) = *(int *)(iVar3 + 4) + *(int *)(iVar5 + 4) + 0x10;
      uVar1 = FUN_600dfd6a(iVar5);
      *(undefined4 *)(iVar5 + 0xc) = uVar1;
      puVar2 = (undefined4 *)private_heap__60083534(iVar5);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = *(undefined4 *)(iVar5 + 4);
        uVar6 = FUN_600dfd6a(puVar2,puVar2);
        *(int *)((int)((ulonglong)uVar6 >> 0x20) + 0xc) = (int)uVar6;
      }
    }
  }
  return;
}


