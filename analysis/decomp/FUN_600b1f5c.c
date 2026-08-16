// 600b1f5c  FUN_600b1f5c  size=218 bytes
// --- callers ---
//   600a29a0 FUN_600a29a0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4
FUN_600b1f5c(undefined2 param_1,undefined2 param_2,int param_3,undefined1 param_4,undefined1 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x14,DAT_600b2038,0x75);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xc;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 3;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 9;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    local_14 = (undefined1 *)(iVar1 + 0xf);
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((2 - iVar3) + param_3);
      local_14 = local_14 + 1;
    }
    *local_14 = param_4;
    local_14[1] = param_5;
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


