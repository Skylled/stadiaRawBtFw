// 600ee298  FUN_600ee298  size=80 bytes
// --- callers ---
//   6006d7a0 FUN_6006d7a0
// --- callees ---
//   600f045e FUN_600f045e
//   600f16ae FUN_600f16ae
//   600d937c thunk_EXT_FUN_00007dac
//   600d9378 thunk_EXT_FUN_00007d64


bool FUN_600ee298(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = true;
  thunk_EXT_FUN_00007d64();
  iVar2 = FUN_600f045e(param_1,2);
  if ((iVar2 == 0) && (iVar2 = FUN_600f045e(param_1,1), iVar2 == 0)) {
    FUN_600f16ae(param_1);
  }
  else {
    bVar1 = false;
  }
  thunk_EXT_FUN_00007dac();
  return !bVar1;
}


