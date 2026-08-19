// 600dde54  FUN_600dde54  size=102 bytes
// --- callers ---
//   600ddeba FUN_600ddeba
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60101fcc FUN_60101fcc
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d378 thunk_EXT_FUN_0000b532


int * FUN_600dde54(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_118 [256];
  
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    if (0xffffff < param_2) {
      FUN_60101fcc();
    }
    iVar1 = thunk_EXT_FUN_0000b532(param_2 * 0x100);
  }
  iVar2 = param_2 * 0x100 + iVar1;
  param_1[2] = iVar2;
  *param_1 = iVar1;
  param_1[1] = iVar1;
  thunk_EXT_FUN_0000b5ba(auStack_118,0,0x100);
  for (uVar3 = 0; uVar3 != param_2; uVar3 = uVar3 + 1) {
    thunk_EXT_FUN_0000b572(iVar1 + uVar3 * 0x100,auStack_118,0x100);
  }
  param_1[1] = iVar2;
  return param_1;
}


