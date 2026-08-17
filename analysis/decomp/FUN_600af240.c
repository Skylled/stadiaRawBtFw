// 600af240  FUN_600af240  size=138 bytes
// --- callers ---
//   600ab424 FUN_600ab424
//   600ab318 FUN_600ab318
// --- callees ---
//   600f68f0 FUN_600f68f0
//   600d92f8 FUN_600d92f8
//   600d92fc FUN_600d92fc


undefined4 * FUN_600af240(undefined4 *param_1,undefined4 *param_2,short param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)FUN_600d92f8(DAT_600af2cc);
  while( true ) {
    if (local_1c == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar2 = (undefined4 *)*local_1c;
    iVar1 = FUN_600f68f0(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],*puVar2,puVar2[1],
                         puVar2[2],puVar2[3],puVar2[4]);
    if (((iVar1 != 0) &&
        (iVar1 = FUN_600f68f0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],puVar2[5],
                              puVar2[6],puVar2[7],puVar2[8],puVar2[9]), iVar1 != 0)) &&
       (param_3 == *(short *)(puVar2 + 10))) break;
    local_1c = (undefined4 *)FUN_600d92fc(local_1c);
  }
  return local_1c;
}


