// 6005842c  FUN_6005842c  size=126 bytes
// --- callers ---
// --- callees ---
//   600cbc60 FUN_600cbc60
//   600cbccc FUN_600cbccc
//   600cc984 FUN_600cc984
//   600cc8f8 FUN_600cc8f8
//   6013cf90 thunk_EXT_FUN_0000b5ba


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6005842c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 uVar6;
  undefined4 unaff_r7;
  undefined4 unaff_lr;
  
  pbVar1 = _DAT_600584ac;
  DataMemoryBarrier(0x1b);
  bVar5 = *_DAT_600584ac & 1;
  if (((*_DAT_600584ac & 1) == 0) && (iVar2 = FUN_600cc8f8(_DAT_600584ac), iVar2 != 0)) {
    puVar3 = (undefined1 *)thunk_EXT_FUN_0000b5ba(_DAT_600584b0,bVar5,0x200);
    puVar3[0x20c] = bVar5;
    puVar3[0x20d] = bVar5;
    *puVar3 = 2;
    *(undefined1 **)(puVar3 + 0x200) = puVar3 + 1;
    *(undefined4 *)(puVar3 + 0x208) = 2;
    *(undefined4 *)(puVar3 + 0x204) = 0x1fb;
    puVar3[1] = 0x7b;
    puVar3[2] = 0x7d;
    FUN_600cc984(pbVar1);
  }
  if (*(char *)(param_2 + 0xb) == '\0') {
    FUN_600cbccc(_DAT_600584b0,param_2);
  }
  else if (*(char *)(param_2 + 0xb) == '\x01') {
    FUN_600cbc60(_DAT_600584b0,param_2);
  }
  uVar4 = _DAT_600584b4;
  iVar2 = param_1[6];
  if (iVar2 == 0) {
    uVar4 = 0xe;
  }
  else {
    uVar6 = *(undefined4 *)*param_1;
    thunk_EXT_FUN_0000b4c2(iVar2);
    FUN_600cbb7c(iVar2 + 100,uVar6,0,uVar4,param_4,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_lr);
    uVar4 = FUN_60101302(iVar2,iVar2 + 100,*(int *)(iVar2 + 0x26c) + 4,0x32);
    thunk_EXT_FUN_00007d10(iVar2);
  }
  return uVar4;
}


