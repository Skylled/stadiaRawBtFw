// 600d8b6c  FUN_600d8b6c  size=50 bytes
// --- callers ---
//   6006a9c8 gatt_server__6006a9c8
// --- callees ---


int FUN_600d8b6c(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (*(int *)(param_1 + 0x1714) == iVar1) {
      return 0;
    }
    if (*(ushort *)(*(int *)(param_1 + iVar1 * 0x11c + 0x244) + 8) == param_2) break;
    iVar1 = iVar1 + 1;
  }
  return param_1 + 0x230 + iVar1 * 0x11c;
}


