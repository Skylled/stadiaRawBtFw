// 60094dc4  FUN_60094dc4  size=220 bytes
// --- callers ---
// --- callees ---
//   600fd8c4 FUN_600fd8c4
//   600fd6aa FUN_600fd6aa
//   600ef974 FUN_600ef974
//   600c611c FUN_600c611c
//   600fd6d6 FUN_600fd6d6
//   600fd83a FUN_600fd83a
//   6009506c FUN_6009506c
//   60094f58 FUN_60094f58
//   600ef900 FUN_600ef900
//   600c66e8 FUN_600c66e8
//   60094d24 FUN_60094d24
//   600fee40 FUN_600fee40
//   600fd630 FUN_600fd630


undefined1 FUN_60094dc4(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_d;
  int local_c;
  
  uVar1 = DAT_60094f10;
  local_d = 1;
  switch(*param_1) {
  case 0x1d00:
    FUN_600fd83a(DAT_60094f10,param_1);
    break;
  default:
    if (*param_1 == 0x1d0d) {
      local_c = FUN_600ef900(param_1);
    }
    else if (*param_1 == 0x1d11) {
      local_c = FUN_600ef974(param_1);
    }
    else {
      local_c = FUN_6009506c(param_1[3]);
    }
    if (local_c != 0) {
      local_d = FUN_60094d24(local_c,*param_1,param_1);
    }
    break;
  case 0x1d02:
    FUN_600fd8c4(DAT_60094f10,param_1);
    break;
  case 0x1d0c:
    FUN_600c66e8(DAT_60094f10,param_1);
    break;
  case 0x1d16:
    FUN_600fd6aa(DAT_60094f10,param_1);
    break;
  case 0x1d17:
    FUN_600c611c(DAT_60094f10,param_1);
    break;
  case 0x1d18:
    uVar2 = FUN_60094f58((char)param_1[4]);
    FUN_600fd6d6(uVar1,uVar2);
    break;
  case 0x1d19:
    FUN_600fee40(DAT_60094f10,param_1);
    break;
  case 0x1d1a:
    FUN_600fd630(DAT_60094f10);
  }
  return local_d;
}


