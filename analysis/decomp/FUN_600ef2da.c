// 600ef2da  FUN_600ef2da  size=182 bytes
// --- callers ---
//   600eedee FUN_600eedee
//   600ef6ec FUN_600ef6ec
//   600ee522 FUN_600ee522
//   600ee4c8 FUN_600ee4c8
//   600c67ac FUN_600c67ac
//   600ee45a FUN_600ee45a
//   600eeffa FUN_600eeffa
//   600ef510 FUN_600ef510
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   60094f14 FUN_60094f14


bool FUN_600ef2da(short *param_1,short *param_2,char param_3)

{
  int iVar1;
  bool bVar2;
  short asStack_30 [8];
  short asStack_20 [8];
  short *local_10;
  short *local_c;
  
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    if (param_3 == '\0') {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  else if ((*param_1 == 2) && (*param_2 == 2)) {
    bVar2 = param_1[2] == param_2[2];
  }
  else {
    if (*param_1 == 2) {
      FUN_60094f14(asStack_20,param_1[2]);
      local_c = asStack_20;
    }
    else {
      local_c = param_1 + 2;
    }
    if (*param_2 == 2) {
      FUN_60094f14(asStack_30,param_2[2]);
      local_10 = asStack_30;
    }
    else {
      local_10 = param_2 + 2;
    }
    iVar1 = thunk_EXT_FUN_0000b554(local_c,local_10,0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}


