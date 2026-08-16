// 600bb7e4  FUN_600bb7e4  size=276 bytes
// --- callers ---
//   600f9a70 FUN_600f9a70
//   600f8d34 FUN_600f8d34
//   600bbbf8 FUN_600bbbf8
//   600f8122 FUN_600f8122
//   600f8208 FUN_600f8208
//   600f8f7a FUN_600f8f7a
//   600bbb2c FUN_600bbb2c
//   600f9ae6 FUN_600f9ae6
//   600f9906 FUN_600f9906
//   600f8ed0 FUN_600f8ed0
//   600f8de8 FUN_600f8de8
//   600f99ee FUN_600f99ee
//   600f9462 FUN_600f9462
//   600f8c6a FUN_600f8c6a
// --- callees ---
//   600bb8f8 FUN_600bb8f8
//   6006dcdc FUN_6006dcdc


int FUN_600bb7e4(int param_1,ushort param_2,undefined1 param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar2 = FUN_6006dcdc(2,DAT_600bb900,0x158);
  if (iVar2 == 0) {
    iVar2 = FUN_600bb8f8();
    return iVar2;
  }
  *(undefined2 *)(iVar2 + 4) = 0;
  *(ushort *)(iVar2 + 2) = param_2 + 0xc;
  *(char *)(iVar2 + 8) = (char)*(undefined2 *)(param_1 + 2);
  *(byte *)(iVar2 + 9) = (byte)((ushort)*(undefined2 *)(param_1 + 2) >> 8) | 0x20;
  cVar1 = (char)param_2;
  *(char *)(iVar2 + 10) = cVar1 + '\b';
  *(char *)(iVar2 + 0xb) = (char)(param_2 + 8 >> 8);
  *(char *)(iVar2 + 0xc) = cVar1 + '\x04';
  *(char *)(iVar2 + 0xd) = (char)(param_2 + 4 >> 8);
  if (*(char *)(param_1 + 0x32) == '\x02') {
    *(undefined1 *)(iVar2 + 0xe) = 5;
    *(undefined1 *)(iVar2 + 0xf) = 0;
  }
  else {
    *(undefined1 *)(iVar2 + 0xe) = 1;
    *(undefined1 *)(iVar2 + 0xf) = 0;
  }
  local_c = (undefined1 *)(iVar2 + 0x10);
  *local_c = param_3;
  *(undefined1 *)(iVar2 + 0x11) = param_4;
  *(char *)(iVar2 + 0x12) = cVar1;
  *(char *)(iVar2 + 0x13) = (char)(param_2 >> 8);
  return iVar2;
}


