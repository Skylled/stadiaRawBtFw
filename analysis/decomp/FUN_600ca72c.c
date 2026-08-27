// 600ca72c  FUN_600ca72c  size=140 bytes
// --- callers ---
//   60051b50 stats__60051b50
//   60051890 FUN_60051890
// --- callees ---
//   6013d1c0 thunk_EXT_FUN_00001434
//   6013d2d0 thunk_EXT_FUN_0000713c
//   6010095a FUN_6010095a
//   6013d0e0 thunk_EXT_FUN_0000728c


int FUN_600ca72c(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_r1;
  int iVar3;
  int iVar4;
  int iVar5;
  
  thunk_EXT_FUN_0000713c();
  iVar1 = DAT_600ca7cc;
  if (extraout_r1 < *DAT_600ca7b8) {
    iVar1 = 0;
  }
  else {
    iVar5 = 0;
    iVar4 = 0;
    do {
      iVar3 = iVar1 + iVar5;
      iVar5 = iVar5 + -0x14;
      iVar3 = FUN_6010095a(iVar4 * 0x24 + param_1,iVar3,1);
      iVar4 = iVar4 + iVar3;
    } while (iVar5 != -0x280);
    iVar5 = FUN_6010095a(iVar4 * 0x24 + param_1,*DAT_600ca7bc,2,DAT_600ca7bc,param_4);
    iVar1 = FUN_6010095a((iVar4 + iVar5) * 0x24 + param_1,*DAT_600ca7c0,2);
    iVar1 = iVar4 + iVar5 + iVar1;
    iVar4 = FUN_6010095a(iVar1 * 0x24 + param_1,DAT_600ca7c4,4);
    iVar1 = iVar1 + iVar4;
    iVar4 = FUN_6010095a(iVar1 * 0x24 + param_1,DAT_600ca7c8,3);
    iVar1 = iVar1 + iVar4;
    if (param_3 != (undefined4 *)0x0) {
      uVar2 = thunk_EXT_FUN_00001434();
      *param_3 = uVar2;
    }
  }
  thunk_EXT_FUN_0000728c();
  return iVar1;
}


