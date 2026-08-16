// 600a9b04  FUN_600a9b04  size=318 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600aa3cc FUN_600aa3cc
//   600a9234 FUN_600a9234
//   600a96d8 FUN_600a96d8
//   600d9250 FUN_600d9250
//   600d9306 FUN_600d9306
//   600aa340 FUN_600aa340
//   6006ddd8 FUN_6006ddd8


void FUN_600a9b04(byte param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  byte *local_10;
  int local_c;
  
  iVar5 = (uint)param_1 * 0x34 + 0xa0 + DAT_600a9c44;
  local_c = 0;
  local_10 = (byte *)0x0;
  local_14 = 0;
  uVar1 = *param_2;
  *(ushort *)(iVar5 + 0x18) = (ushort)(byte)param_2[1];
  uVar2 = (ushort)(byte)param_2[3] * 0x100 + (ushort)(byte)param_2[2];
  if (((uVar2 != 0xc03) && (uVar2 != 0xc35)) && (uVar2 != 0)) {
    local_c = FUN_600d9250(iVar5 + 0xc);
    if (local_c != 0) {
      local_10 = (byte *)(local_c + 8 + (uint)*(ushort *)(local_c + 4));
      uVar3 = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
      local_10 = local_10 + 2;
      if (uVar3 == uVar2) {
        if ((uVar3 & 0xfc00) == 0xfc00) {
          local_14 = *(undefined4 *)(local_c + 8);
        }
      }
      else {
        local_10 = (byte *)0x0;
      }
    }
    iVar4 = FUN_600d9306(iVar5 + 0xc);
    if (iVar4 == 0) {
      FUN_600aa340(iVar5 + 0x1c,param_1 + 0x2c,8);
    }
    else {
      FUN_600aa3cc(iVar5 + 0x1c);
    }
  }
  FUN_600a96d8(uVar2,uVar1,local_10,local_14,param_1);
  if (local_c != 0) {
    FUN_6006ddd8(local_c,DAT_600a9c48,0x90c);
  }
  FUN_600a9234(param_1,0);
  return;
}


