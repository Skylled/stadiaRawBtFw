// 600d4694  thunk_FUN_6005e6e8  size=4 bytes
// --- callers ---
// --- callees ---


undefined4 thunk_FUN_6005e6e8(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  code *pcVar5;
  
  iVar2 = thunk_EXT_FUN_0000b4cc(DAT_6005e72c,0);
  iVar1 = DAT_6005e730;
  if (iVar2 == 0) {
    uVar3 = 0xd;
  }
  else {
    FUN_6005e25c(DAT_6005e730);
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined1 *)(iVar1 + 4) = 1;
    piVar4 = *(int **)(iVar1 + 0xc);
    pcVar5 = *(code **)*piVar4;
    uVar3 = (*(code *)((undefined4 *)*piVar4)[5])(piVar4);
    uVar3 = (*pcVar5)(piVar4,0,uVar3);
    thunk_EXT_FUN_00007d10(DAT_6005e72c);
  }
  return uVar3;
}


