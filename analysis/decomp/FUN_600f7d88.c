// 600f7d88  FUN_600f7d88  size=424 bytes
// --- callers ---
//   600b9e28 FUN_600b9e28
// --- callees ---
//   600f8c6a FUN_600f8c6a
//   600f8208 FUN_600f8208
//   600b5844 FUN_600b5844
//   600aa3cc FUN_600aa3cc


void FUN_600f7d88(int param_1,char *param_2,ushort param_3)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  cVar1 = param_2[1];
  if (param_2 + 4 + (ushort)((ushort)(byte)param_2[3] * 0x100 + (ushort)(byte)param_2[2]) <=
      param_2 + param_3) {
    if (*param_2 == '\x12') {
      uVar2 = (ushort)(byte)param_2[5] * 0x100 + (ushort)(byte)param_2[4];
      uVar3 = (ushort)(byte)param_2[7] * 0x100 + (ushort)(byte)param_2[6];
      uVar4 = (ushort)(byte)param_2[9] * 0x100 + (ushort)(byte)param_2[8];
      uVar5 = (ushort)(byte)param_2[0xb] * 0x100 + (ushort)(byte)param_2[10];
      if (*(char *)(param_1 + 10) == '\0') {
        if (((((uVar2 < 6) || (0xc80 < uVar2)) || (uVar3 < 6)) || ((0xc80 < uVar3 || (500 < uVar4)))
            ) || ((uVar5 < 10 || ((0xc80 < uVar5 || (uVar3 < uVar2)))))) {
          FUN_600f8208(param_1,1,cVar1);
        }
        else {
          FUN_600f8208(param_1,0,cVar1);
          *(ushort *)(param_1 + 0x3a) = uVar2;
          *(ushort *)(param_1 + 0x3c) = uVar3;
          *(ushort *)(param_1 + 0x3e) = uVar4;
          *(ushort *)(param_1 + 0x40) = uVar5;
          *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 2;
          FUN_600b5844(param_1);
        }
      }
      else {
        FUN_600f8c6a(param_1,0,cVar1,0,0);
      }
    }
    else if (*param_2 == '\x13') {
      *(undefined1 *)(param_1 + 0x34) = 0;
      FUN_600aa3cc(param_1 + 0x44);
    }
    else {
      FUN_600f8c6a(param_1,0,cVar1,0,0);
    }
  }
  return;
}


