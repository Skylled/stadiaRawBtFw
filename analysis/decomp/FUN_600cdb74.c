// 600cdb74  FUN_600cdb74  size=56 bytes
// --- callers ---
//   6004c700 FUN_6004c700
// --- callees ---
//   6013ced0 FUN_6013ced0
//   600521b8 heap_5_improved__600521b8


void FUN_600cdb74(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = DAT_600cdbac;
  iVar3 = DAT_600cdbb0 - DAT_600cdbac;
  for (iVar4 = 0; iVar2 = DAT_600cdbb8, iVar1 = DAT_600cdbb4, iVar4 != iVar3 >> 2; iVar4 = iVar4 + 1
      ) {
    (**(code **)(iVar5 + iVar4 * 4))();
  }
  FUN_6013ced0();
  for (iVar5 = 0; iVar5 != iVar2 - iVar1 >> 2; iVar5 = iVar5 + 1) {
    (**(code **)(iVar1 + iVar5 * 4))();
  }
  return;
}


