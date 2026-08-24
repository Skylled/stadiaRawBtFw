// 600edfde  FUN_600edfde  size=32 bytes
// --- callers ---
//   6004b93e FUN_6004b93e
// --- callees ---
//   6013d038 thunk_EXT_FUN_00008832


undefined4 FUN_600edfde(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)thunk_EXT_FUN_00008832(8);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    DataMemoryBarrier(0x1b);
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}


