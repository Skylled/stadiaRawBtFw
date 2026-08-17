// 600bbb2c  FUN_600bbb2c  size=200 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
// --- callees ---
//   600b9408 FUN_600b9408
//   6006e0a4 FUN_6006e0a4
//   6006e0bc FUN_6006e0bc
//   600bb7e4 FUN_600bb7e4


void FUN_600bbb2c(int param_1,char param_2,int param_3,ushort param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort local_28;
  undefined1 *local_14;
  
  if ((param_2 != '\0') && (param_2 != *(char *)(param_1 + 0xc))) {
    *(char *)(param_1 + 0xc) = param_2;
    uVar2 = FUN_6006e0bc(2);
    if (uVar2 < 0x15) {
      uVar2 = FUN_6006e0a4(2);
      if (*(ushort *)(DAT_600bbbf4 + 0x5a) < uVar2) {
        sVar1 = *(short *)(DAT_600bbbf4 + 0x58);
      }
      else {
        sVar1 = FUN_6006e0a4(2);
      }
      local_28 = param_4;
      if ((ushort)(sVar1 - 0x14U) < param_4) {
        local_28 = 0;
      }
      iVar3 = FUN_600bb7e4(param_1,local_28,9,param_2);
      if (iVar3 != 0) {
        if (local_28 != 0) {
          local_14 = (undefined1 *)(iVar3 + 0x14);
          for (iVar4 = 0; iVar4 < (int)(uint)local_28; iVar4 = iVar4 + 1) {
            *local_14 = *(undefined1 *)(iVar4 + param_3);
            local_14 = local_14 + 1;
          }
        }
        FUN_600b9408(param_1,0,iVar3);
      }
    }
  }
  return;
}


