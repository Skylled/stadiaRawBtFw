// 600df918  FUN_600df918  size=170 bytes
// --- callers ---
//   600df918 FUN_600df918
//   600df9c2 FUN_600df9c2
// --- callees ---
//   600df918 FUN_600df918
//   600df9c2 FUN_600df9c2
//   600dfadc FUN_600dfadc
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600df918(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_28 [16];
  int *local_18;
  int *local_14;
  
  iVar4 = *(int *)(param_1 + 4);
  uVar2 = (uint)*(byte *)(iVar4 + 4);
  if ((uVar2 & 0xf) == 8) {
    for (piVar3 = (int *)**(undefined4 **)(param_1 + 0x10); piVar3 != (int *)0x0;
        piVar3 = (int *)piVar3[2]) {
      iVar4 = *(int *)(*piVar3 + 8);
      *(undefined1 *)(piVar3 + 3) = 0;
      FUN_600dfadc(auStack_28,iVar4,piVar3[1]);
      local_18 = (int *)piVar3[1];
      local_14 = piVar3 + 3;
      if ((*(byte *)(iVar4 + 4) & 0xc0) == 0x80) {
        local_18 = piVar3 + 1;
      }
      FUN_600df918(auStack_28);
    }
    return;
  }
  uVar1 = uVar2 & 0xc0;
  if ((*(byte *)(iVar4 + 4) & 0xc0) == 0) {
    if ((uVar2 & 0x30) == 0x10) {
      if (*(undefined1 **)(param_1 + 0x14) != *(undefined1 **)(param_1 + 0x10)) {
        **(undefined1 **)(param_1 + 0x14) = (char)uVar1;
      }
    }
    else if ((int)(uVar2 << 0x1a) < 0) goto LAB_600df998;
    if ((uVar2 & 0xf) == 7) {
      FUN_600df9c2(*(int *)(iVar4 + 0x15),*(undefined4 *)(param_1 + 0x10));
    }
    else if (*(int *)(iVar4 + 0x15) == 0) {
      thunk_EXT_FUN_0000b5ba(*(undefined4 *)(param_1 + 0x10),0,*(undefined4 *)(iVar4 + 0xd));
    }
    else {
      thunk_EXT_FUN_0000b572();
    }
  }
  else {
    if (uVar1 != 0x80) {
      return;
    }
    uVar1 = 0;
    **(undefined4 **)(param_1 + 0x10) = 0;
    if (-1 < (int)(uVar2 << 0x1a)) {
      return;
    }
LAB_600df998:
    **(uint **)(param_1 + 0x14) = uVar1;
  }
  return;
}


