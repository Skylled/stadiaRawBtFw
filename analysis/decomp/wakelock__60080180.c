// 60080180  wakelock__60080180  size=132 bytes
// src: wakelock.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600df014 FUN_600df014
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010165c FUN_6010165c


/* src: wakelock.cc */

undefined4 wakelock__60080180(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  DataMemoryBarrier(0x1b);
  piVar5 = param_1 + 2;
  DataMemoryBarrier(0x1b);
  if (param_1[2] == -1) {
    FUN_6010165c(0x28,DAT_600801d8,0x13,DAT_600801d4);
    uVar3 = 8;
  }
  else {
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar5);
      iVar4 = *piVar5;
      bVar2 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar2);
    *piVar5 = iVar4 + 1;
    DataMemoryBarrier(0x1b);
    if (iVar4 == 0) {
      bVar1 = *(byte *)(param_1 + 1);
      iVar4 = *param_1;
      thunk_EXT_FUN_0000b4c2(iVar4 + 0xbc,(uint)bVar1,0,param_4);
      *(uint *)(iVar4 + 0x14c) = *(uint *)(iVar4 + 0x14c) | 1 << (uint)bVar1;
      uVar3 = FUN_600df014(iVar4);
      thunk_EXT_FUN_00007d10(iVar4 + 0xbc);
      return uVar3;
    }
    uVar3 = 0;
  }
  return uVar3;
}


