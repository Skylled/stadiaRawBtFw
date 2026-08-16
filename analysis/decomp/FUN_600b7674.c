// 600b7674  FUN_600b7674  size=390 bytes
// --- callers ---
//   600f83a0 FUN_600f83a0
//   600b7800 FUN_600b7800
//   600f832a FUN_600f832a
//   600b7cba FUN_600b7cba
//   600b7db8 FUN_600b7db8
// --- callees ---
//   600bce60 FUN_600bce60
//   600b731c FUN_600b731c
//   600b9408 FUN_600b9408
//   600f82c4 FUN_600f82c4
//   600f8264 FUN_600f8264
//   6006dcdc FUN_6006dcdc
//   600aa4c4 FUN_600aa4c4


void FUN_600b7674(int param_1,short param_2,ushort param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((*(char *)(param_1 + 5) != '\0') && (*(char *)(param_1 + 4) == '\x06')) {
    if (param_3 == 0x10) {
      *(undefined1 *)(param_1 + 0xba) = 1;
      FUN_600f82c4(param_1);
      FUN_600b731c(param_1);
    }
    param_3 = param_3 | param_2 << 2 | 1U | (ushort)*(byte *)(param_1 + 0xb2) << 8;
    iVar2 = FUN_6006dcdc(2,DAT_600b77fc,0x21e);
    if (iVar2 != 0) {
      *(undefined2 *)(iVar2 + 4) = 4;
      *(undefined2 *)(iVar2 + 2) = 6;
      puVar3 = (undefined1 *)(iVar2 + 8 + (uint)*(ushort *)(iVar2 + 4));
      *puVar3 = 4;
      puVar3[1] = 0;
      puVar3[2] = (char)*(undefined2 *)(param_1 + 2);
      puVar3[3] = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
      puVar3[4] = (char)param_3;
      puVar3[5] = (char)(param_3 >> 8);
      if (*(char *)(param_1 + 0x11f) == '\x03') {
        *puVar3 = 2;
        puVar3[1] = 0;
      }
      else {
        uVar1 = FUN_600f8264(iVar2);
        puVar3[6] = (char)uVar1;
        puVar3[7] = (char)((ushort)uVar1 >> 8);
        *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + 2;
      }
      *(undefined2 *)(iVar2 + 6) = 2;
      FUN_600bce60(iVar2,param_1);
      FUN_600b9408(*(undefined4 *)(param_1 + 300),0,iVar2);
      *(undefined1 *)(param_1 + 0xb3) = *(undefined1 *)(param_1 + 0xb2);
      if (*(char *)(param_1 + 0xfe) != '\0') {
        FUN_600aa4c4(param_1 + 0xe8);
      }
    }
  }
  return;
}


