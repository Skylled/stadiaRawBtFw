// 600d206c  FUN_600d206c  size=212 bytes
// --- callers ---
//   600563b8 FUN_600563b8
// --- callees ---
//   600d3244 FUN_600d3244
//   600d332a FUN_600d332a
//   600d3256 FUN_600d3256
//   60056968 FUN_60056968


int FUN_600d206c(int param_1,int param_2,int param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_30;
  undefined2 local_2c;
  ushort local_2a;
  undefined1 local_28;
  byte local_27;
  undefined2 local_26;
  undefined1 local_24;
  
  if (param_1 == 0) {
    iVar1 = 3;
  }
  else {
    *(int *)(param_1 + 0xc) = param_2;
    iVar1 = FUN_60056968(*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x14) != 0) {
        FUN_600d332a(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0x14),0);
        iVar1 = FUN_600d3256(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x14));
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      for (uVar3 = 0; (uVar3 & 0xff) < (uint)*(byte *)(param_2 + 0x3c); uVar3 = uVar3 + 1) {
        iVar2 = *(int *)(param_2 + uVar3 * 0xc);
        if (((int)((uint)*(byte *)(iVar2 + 2) << 0x18) < 0) && ((*(byte *)(iVar2 + 3) & 3) == 3)) {
          local_30 = *(undefined4 *)(param_1 + 8);
          local_27 = *(byte *)(iVar2 + 2) & 0xf;
          local_26 = 0x301;
          local_28 = *(undefined1 *)(iVar2 + 6);
          local_2a = (ushort)(((uint)*(ushort *)(iVar2 + 4) << 0x15) >> 0x15);
          local_24 = 0;
          local_2c = 3000;
          iVar2 = FUN_600d3244(*(undefined4 *)(param_1 + 4),param_1 + 0x14,&local_30);
          iVar1 = 0;
          if (iVar2 != 0) goto LAB_600d212e;
          break;
        }
      }
      if (param_3 == 0) {
        if (param_4 != (code *)0x0) {
          (*param_4)(param_5,0,0,0);
        }
      }
      else {
LAB_600d212e:
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}


