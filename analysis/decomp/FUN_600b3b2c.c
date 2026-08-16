// 600b3b2c  FUN_600b3b2c  size=206 bytes
// --- callers ---
//   600a1900 FUN_600a1900
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


undefined4 FUN_600b3b2c(byte param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac((uint)param_1 * 3 + 0xc,DAT_600b3bfc,0x879);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(ushort *)(iVar1 + 2) = (ushort)param_1 * 3 + 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x3a;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(char *)(iVar1 + 10) = (char)*(undefined2 *)(iVar1 + 2) + -3;
    local_14 = (undefined1 *)(iVar1 + 0xc);
    *(byte *)(iVar1 + 0xb) = param_1;
    local_18 = 0;
    while( true ) {
      if ((int)(uint)param_1 <= local_18) break;
      for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
        *local_14 = *(undefined1 *)(param_2 + local_18 * 3 + (2 - iVar3));
        local_14 = local_14 + 1;
      }
      local_18 = local_18 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


