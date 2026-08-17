// 6009ff18  FUN_6009ff18  size=130 bytes
// --- callers ---
//   600f0bb8 FUN_600f0bb8
//   600b89b8 FUN_600b89b8
//   600f06dc FUN_600f06dc
//   600f0a98 FUN_600f0a98
//   600f0a52 FUN_600f0a52
//   600f16ae FUN_600f16ae
//   600f1b72 FUN_600f1b72
//   600f0ac8 FUN_600f0ac8
//   600a42d0 FUN_600a42d0
//   600f0e98 FUN_600f0e98
//   600f1700 FUN_600f1700
//   6009afd4 FUN_6009afd4
//   6009fe40 FUN_6009fe40
//   600979e4 FUN_600979e4
//   600f0726 FUN_600f0726
//   600f20ac FUN_600f20ac
//   600c0434 FUN_600c0434
//   600f194c FUN_600f194c
//   600f19d2 FUN_600f19d2
//   6009beb0 FUN_6009beb0
//   600a65f4 FUN_600a65f4
//   600c0698 FUN_600c0698
//   60099dd0 FUN_60099dd0
//   6009ad00 FUN_6009ad00
//   600a5540 FUN_600a5540
//   6009b77c FUN_6009b77c
//   6009931c FUN_6009931c
//   600f0836 FUN_600f0836
//   600f0994 FUN_600f0994
//   60099204 FUN_60099204
//   600f1746 FUN_600f1746
//   60099584 FUN_60099584
//   600a59d0 FUN_600a59d0
//   600f068e FUN_600f068e
//   600f0b06 FUN_600f0b06
//   6009b0a8 FUN_6009b0a8
//   600a6d70 FUN_600a6d70
//   600a4a20 FUN_600a4a20
//   600a4820 FUN_600a4820
//   600f0568 FUN_600f0568
//   600faec4 FUN_600faec4
//   6009b290 FUN_6009b290
//   6009fae0 FUN_6009fae0
//   600a5670 FUN_600a5670
//   6009f08c FUN_6009f08c
//   600f096a FUN_600f096a
//   600a62cc FUN_600a62cc
//   600c073c FUN_600c073c
//   600fab0c FUN_600fab0c
//   600f1f5c FUN_600f1f5c
//   600a58f0 FUN_600a58f0
//   600f103a FUN_600f103a
//   600f1a0e FUN_600f1a0e
//   600f04e4 FUN_600f04e4
//   600f0c84 FUN_600f0c84
//   6009a9c4 FUN_6009a9c4
//   600a4984 FUN_600a4984
//   600f1148 FUN_600f1148
//   600bc5c4 FUN_600bc5c4
//   600a3d8c FUN_600a3d8c
// --- callees ---
//   600f0f8e FUN_600f0f8e
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_6009ff18(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = DAT_6009ff9c;
  if (param_1 != 0) {
    for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
      if ((*(ushort *)(local_c + 0x2a) & 0x80) != 0) {
        iVar1 = thunk_EXT_FUN_0000b554(local_c + 0x10,param_1,6);
        if (iVar1 == 0) {
          return local_c;
        }
        iVar1 = thunk_EXT_FUN_0000b554(local_c + 100,param_1,6);
        if (iVar1 == 0) {
          return local_c;
        }
        iVar1 = FUN_600f0f8e(param_1,local_c);
        if (iVar1 != 0) {
          return local_c;
        }
      }
      local_c = local_c + 0xfc;
    }
  }
  return 0;
}


