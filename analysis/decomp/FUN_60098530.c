// 60098530  FUN_60098530  size=190 bytes
// --- callers ---
//   600eff14 FUN_600eff14
//   600985f8 FUN_600985f8
// --- callees ---
//   600a1394 FUN_600a1394
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a13f0 FUN_600a13f0


undefined4
FUN_60098530(undefined4 param_1,undefined2 param_2,byte param_3,byte param_4,byte param_5,
            byte param_6)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined1 local_28 [20];
  byte *local_14;
  
  if ((param_3 & 0xf8) == 0) {
    local_14 = local_28;
    thunk_EXT_FUN_0000b5ba(local_28,0,0x14);
    pbVar1 = local_14 + 1;
    *local_14 = 0xb;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = 1;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = (char)param_2;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = (char)((ushort)param_2 >> 8);
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = param_3;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = param_4;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = param_5;
    local_14 = pbVar1;
    pbVar1 = local_14 + 1;
    *local_14 = param_6;
    local_14 = pbVar1;
    FUN_600a13f0(DAT_600985f0,1);
    uVar2 = FUN_600a1394(0xfce9,8,local_28,DAT_600985f4);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}


