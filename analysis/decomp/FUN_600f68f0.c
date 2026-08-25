// 600f68f0  FUN_600f68f0  size=256 bytes
// --- callers ---
//   600ae0dc FUN_600ae0dc
//   600ac9a4 FUN_600ac9a4
//   600ae4e0 FUN_600ae4e0
//   600f5130 FUN_600f5130
//   600af444 FUN_600af444
//   600af240 FUN_600af240
//   600afbd0 FUN_600afbd0
// --- callees ---
//   600af9a0 FUN_600af9a0
//   600af95c FUN_600af95c
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600f68f0(short param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,short param_6,uint param_7)

{
  int iVar1;
  bool bVar2;
  undefined4 auStack_40 [4];
  uint auStack_30 [4];
  undefined4 *local_20;
  uint *local_1c;
  uint local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 == 0) || (param_6 == 0)) {
    bVar2 = true;
  }
  else if ((param_1 == 2) && (param_6 == 2)) {
    bVar2 = (param_2 & 0xffff) == (param_7 & 0xffff);
  }
  else if ((param_1 == 4) && (param_6 == 4)) {
    bVar2 = param_2 == param_7;
  }
  else {
    local_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    if (param_1 == 2) {
      FUN_600af95c(auStack_30,param_2 & 0xffff);
      local_1c = auStack_30;
    }
    else if (param_1 == 4) {
      FUN_600af9a0(auStack_30,param_2);
      local_1c = auStack_30;
    }
    else {
      local_1c = &local_c;
    }
    if (param_6 == 2) {
      FUN_600af95c(auStack_40,param_7 & 0xffff);
      local_20 = auStack_40;
    }
    else if (param_6 == 4) {
      FUN_600af9a0(auStack_40,param_7);
      local_20 = auStack_40;
    }
    else {
      local_20 = &param_7;
    }
    iVar1 = thunk_EXT_FUN_0000b554(local_1c,local_20,0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}


