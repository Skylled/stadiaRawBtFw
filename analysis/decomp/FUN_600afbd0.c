// 600afbd0  FUN_600afbd0  size=176 bytes
// --- callers ---
//   600ab318 FUN_600ab318
//   600ab424 FUN_600ab424
// --- callees ---
//   600f4ed6 FUN_600f4ed6
//   600f68f0 FUN_600f68f0
//   600b0444 FUN_600b0444


byte FUN_600afbd0(undefined4 *param_1,undefined4 *param_2,short param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_20;
  byte local_19;
  
  local_19 = 0;
  local_20 = DAT_600afc80;
  while( true ) {
    if (9 < local_19) {
      return local_19;
    }
    if ((((*(char *)((int)local_20 + 0x25) != '\0') &&
         (puVar1 = (undefined4 *)FUN_600f4ed6(*local_20), puVar1 != (undefined4 *)0x0)) &&
        (iVar2 = FUN_600f68f0(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],local_20[1],
                              local_20[2],local_20[3],local_20[4],local_20[5]), iVar2 != 0)) &&
       ((iVar2 = FUN_600f68f0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],*puVar1,puVar1[1]
                              ,puVar1[2],puVar1[3],puVar1[4]), iVar2 != 0 &&
        (param_3 == *(short *)(local_20 + 7))))) break;
    local_19 = local_19 + 1;
    local_20 = local_20 + 10;
  }
  FUN_600b0444(*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  return local_19;
}


