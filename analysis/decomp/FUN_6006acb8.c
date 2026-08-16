// 6006acb8  FUN_6006acb8  size=62 bytes
// --- callers ---
//   6006ae20 gatt_server__6006ae20
//   6006ad00 gatt_server__6006ad00
// --- callees ---
//   6006ac00 FUN_6006ac00


bool FUN_6006acb8(int param_1,short param_2,undefined4 param_3)

{
  short *psVar1;
  bool bVar2;
  short local_12;
  undefined4 uStack_10;
  
  uStack_10 = param_3;
  local_12 = param_2;
  psVar1 = (short *)FUN_6006ac00(param_1,*(int *)(param_1 + 0xc00) * 0x30 + param_1,&local_12,
                                 DAT_6006acf8,param_1);
  if (((int)psVar1 - param_1 >> 4) * DAT_6006acfc < *(int *)(param_1 + 0xc00)) {
    bVar2 = *psVar1 == local_12;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


