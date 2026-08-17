// 6009bfb0  FUN_6009bfb0  size=100 bytes
// --- callers ---
//   6009c59c FUN_6009c59c
//   6009dd74 FUN_6009dd74
//   600f1592 FUN_600f1592
// --- callees ---
//   600b0cd4 FUN_600b0cd4


void FUN_6009bfb0(undefined1 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  
  iVar1 = DAT_6009c014;
  *(undefined1 *)(DAT_6009c014 + 0xf) = param_1;
  if (*(char *)(iVar1 + 8) == -1) {
    uVar3 = 1;
  }
  else {
    uVar3 = *(undefined1 *)(iVar1 + 8);
  }
  *(undefined1 *)(iVar1 + 8) = uVar3;
  if (*(short *)(iVar1 + 6) == 0) {
    uVar2 = 0x12;
  }
  else {
    uVar2 = *(undefined2 *)(iVar1 + 6);
  }
  if (*(short *)(iVar1 + 4) == 0) {
    uVar4 = 0x12;
  }
  else {
    uVar4 = *(undefined2 *)(iVar1 + 4);
  }
  FUN_600b0cd4(*(undefined1 *)(iVar1 + 8),uVar2,uVar4,*(undefined1 *)(DAT_6009c018 + 0xa34),param_1)
  ;
  return;
}


