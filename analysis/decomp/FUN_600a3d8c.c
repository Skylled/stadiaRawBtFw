// 600a3d8c  FUN_600a3d8c  size=432 bytes
// --- callers ---
//   600f2afa FUN_600f2afa
// --- callees ---
//   6009a5b0 FUN_6009a5b0
//   6009ff18 FUN_6009ff18
//   60098f34 FUN_60098f34
//   600b9408 FUN_600b9408
//   600bb6dc FUN_600bb6dc
//   600a3a38 FUN_600a3a38


void FUN_600a3d8c(undefined1 param_1,undefined2 param_2,char param_3,undefined2 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = FUN_60098f34(param_2);
  if (iVar2 < 4) {
    iVar5 = iVar2 * 0x14c + 0x110 + DAT_600a3f3c;
    iVar6 = iVar2 * 0x24 + DAT_600a3f3c;
    cVar1 = *(char *)(iVar6 + 0x66c);
    *(char *)(iVar6 + 0x66d) = param_3;
    *(undefined1 *)(iVar6 + 0x66c) = *(undefined1 *)(iVar6 + 0x66d);
    *(undefined2 *)(iVar6 + 0x66a) = param_4;
    iVar3 = FUN_600bb6dc(iVar5 + 6,1);
    if (((iVar3 != 0) &&
        ((*(char *)(iVar6 + 0x66c) == '\0' || (*(char *)(iVar6 + 0x66c) == '\x02')))) &&
       ((*(int *)(iVar3 + 0x5c) != 0 || (*(short *)(iVar3 + 0x88) != 0)))) {
      FUN_600b9408(iVar3,0,0);
    }
    for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
      if ((param_3 == '\0') && (*(char *)(local_14 * 10 + iVar6 + 0x64c + 8) == '\x01')) {
        *(undefined1 *)(local_14 * 10 + iVar6 + 0x64c + 8) = 0;
      }
    }
    if (cVar1 < '\0') {
      FUN_600a3a38(0x80,iVar2,0);
    }
    else {
      for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
        if (*(char *)(local_18 * 0x24 + DAT_600a3f3c + 0x66e) == '\x01') {
          FUN_600a3a38(0x80,local_18,0);
          break;
        }
      }
    }
    for (local_14 = 0; local_14 < 1; local_14 = local_14 + 1) {
      if ((*(byte *)((local_14 + 0xdb) * 8 + DAT_600a3f3c + 8) & 2) != 0) {
        (**(code **)((local_14 + 0xdb) * 8 + DAT_600a3f3c + 4))(iVar5 + 6,param_3,param_4,param_1);
      }
    }
    uVar4 = FUN_6009ff18(iVar5 + 6);
    FUN_6009a5b0(iVar5,uVar4,param_1);
  }
  return;
}


