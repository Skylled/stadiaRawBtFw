// 600a99cc  FUN_600a99cc  size=302 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600a9234 FUN_600a9234
//   600d9250 FUN_600d9250
//   600d9306 FUN_600d9306
//   600aa340 FUN_600aa340
//   6006ddd8 FUN_6006ddd8


void FUN_600a99cc(byte param_1,int param_2,undefined2 param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  iVar3 = (uint)param_1 * 0x34 + 0xa0 + DAT_600a9afc;
  local_c = 0;
  *(ushort *)(iVar3 + 0x18) = (ushort)*(byte *)(param_2 + 1);
  sVar1 = (ushort)*(byte *)(param_2 + 3) * 0x100 + (ushort)*(byte *)(param_2 + 2);
  param_2 = param_2 + 4;
  if (((sVar1 != 0xc03) && (sVar1 != 0xc35)) && (sVar1 != 0)) {
    local_c = FUN_600d9250(iVar3 + 0xc);
    iVar2 = FUN_600d9306(iVar3 + 0xc);
    if (iVar2 == 0) {
      FUN_600aa340(iVar3 + 0x1c,param_1 + 0x2c,8);
    }
    else {
      FUN_600aa3cc(iVar3 + 0x1c);
    }
  }
  if (local_c != 0) {
    FUN_6006ddd8(local_c,DAT_600a9b00,0x8b6,local_c,param_2,param_3);
  }
  FUN_600a9234(param_1,0);
  return;
}


