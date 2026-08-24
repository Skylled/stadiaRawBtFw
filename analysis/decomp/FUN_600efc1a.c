// 600efc1a  FUN_600efc1a  size=172 bytes
// --- callers ---
//   600c6ad0 FUN_600c6ad0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   60095ae8 FUN_60095ae8


bool FUN_600efc1a(short param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,short param_6,short param_7)

{
  int iVar1;
  bool bVar2;
  uint auStack_40 [4];
  undefined2 auStack_30 [8];
  uint *local_20;
  undefined2 *local_1c;
  uint local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_6 == 0) || (param_1 == 0)) {
    bVar2 = true;
  }
  else if ((param_6 == 2) && (param_1 == 2)) {
    local_c._0_2_ = (short)param_2;
    bVar2 = param_7 == (short)local_c;
  }
  else {
    local_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    if (param_6 == 2) {
      FUN_60095ae8(auStack_30,param_7);
      local_1c = auStack_30;
    }
    else {
      local_1c = &param_7;
    }
    if (param_1 == 2) {
      FUN_60095ae8(auStack_40,local_c & 0xffff);
      local_20 = auStack_40;
    }
    else {
      local_20 = &local_c;
    }
    iVar1 = thunk_EXT_FUN_0000b554(local_1c,local_20,0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}


