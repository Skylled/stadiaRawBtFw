// 6009cec8  FUN_6009cec8  size=182 bytes
// --- callers ---
//   600fd3e0 FUN_600fd3e0
// --- callees ---
//   6009cf8c FUN_6009cf8c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600b0b00 FUN_600b0b00


undefined4 FUN_6009cec8(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  ushort *local_14;
  undefined1 *local_10;
  ushort *local_c;
  
  local_c = DAT_6009cf80;
  local_10 = DAT_6009cf84;
  if ((*(byte *)(DAT_6009cf88 + 0x81b) & 2) == 0) {
    uVar2 = 5;
  }
  else {
    local_18 = param_1;
    thunk_EXT_FUN_0000b5ba(DAT_6009cf80,0,0x2c);
    local_14 = local_c + 4;
    *local_c = (ushort)param_1;
    if ((param_1 & 0x2000) == 0) {
      *local_10 = 0;
    }
    else {
      *local_10 = 1;
    }
    uVar2 = FUN_6009cf8c(&local_18,&local_14,param_2);
    *(undefined4 *)(local_c + 2) = uVar2;
    *(ushort **)(local_c + 0x14) = local_14;
    *local_c = ~(ushort)local_18 & *local_c;
    iVar1 = FUN_600b0b00(*(int *)(local_c + 0x14) - (int)(local_c + 4) & 0xff,local_c + 4);
    if (iVar1 == 0) {
      uVar2 = 3;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


