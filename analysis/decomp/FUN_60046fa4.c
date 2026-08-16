// 60046fa4  FUN_60046fa4  size=84 bytes
// --- callers ---
//   60046ffc FUN_60046ffc
//   6004ba16 FUN_6004ba16
// --- callees ---
//   6004904e heap_5_improved__60048774
//   6004bdd6 FUN_6004bdd6
//   60047f1c FUN_60047f1c
//   60047f34 FUN_60047f34


void FUN_60046fa4(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_60047f34(0,1);
  if (iVar2 == 0) {
    iVar2 = heap_5_improved__60048774(0x34);
    if (iVar2 != 0) {
      FUN_6004bdd6(iVar2,0,0x14);
      iVar1 = DAT_60046ff8;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      uVar3 = *(undefined4 *)(iVar1 + 0x18);
      *(undefined1 *)(iVar2 + 0x10) = 1;
      *(undefined4 *)(iVar2 + 4) = uVar3;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x28) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *(undefined4 *)(iVar2 + 0x30) = 0;
      FUN_60047f1c(0,1,iVar2);
    }
    FUN_60047f34(0,1);
    return;
  }
  return;
}


