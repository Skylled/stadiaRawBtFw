// 600af444  FUN_600af444  size=138 bytes
// --- callers ---
//   600ab110 FUN_600ab110
//   600ab318 FUN_600ab318
// --- callees ---
//   600f68f0 FUN_600f68f0


undefined4 * FUN_600af444(undefined4 *param_1,undefined4 *param_2,short param_3)

{
  int iVar1;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)*DAT_600af4d0;
  while( true ) {
    if (local_1c == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = FUN_600f68f0(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],local_1c[2],
                         local_1c[3],local_1c[4],local_1c[5],local_1c[6]);
    if (((iVar1 != 0) &&
        (iVar1 = FUN_600f68f0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],local_1c[7],
                              local_1c[8],local_1c[9],local_1c[10],local_1c[0xb]), iVar1 != 0)) &&
       (param_3 == *(short *)(local_1c + 0xc))) break;
    local_1c = (undefined4 *)*local_1c;
  }
  return local_1c;
}


