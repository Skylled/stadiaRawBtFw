// 600df072  FUN_600df072  size=78 bytes
// --- callers ---
//   6005e020 power_rpcs__6005e020
// --- callees ---
//   60101ac8 FUN_60101ac8
//   601019da FUN_601019da
//   60050c18 FUN_60050c18


undefined1 FUN_600df072(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)(param_1 + 0x118);
  do {
    DataMemoryBarrier(0x1b);
    uVar4 = *puVar2;
    DataMemoryBarrier(0x1b);
    iVar3 = param_2[2];
    iVar1 = FUN_60101ac8(param_2);
    if (iVar1 != 0) {
      uVar4 = FUN_60050c18(uVar4,0,param_2[2] + *param_2,param_2[1] - param_2[2]);
      FUN_601019da(param_2,uVar4,iVar3,0x5d);
    }
    puVar2 = puVar2 + 3;
  } while (puVar2 != (undefined4 *)(param_1 + 0x154));
  return (char)param_2[3];
}


