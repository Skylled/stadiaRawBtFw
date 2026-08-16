// 600cb460  key_value_store__600cb460  size=304 bytes
// src: key_value_store.cc
// --- callers ---
//   60100ffc FUN_60100ffc
// --- callees ---
//   600d37ac FUN_600d37ac
//   60101b76 FUN_60101b76
//   6013d168 thunk_EXT_FUN_0000b554
//   601018de FUN_601018de
//   600db002 FUN_600db002
//   600d37b8 FUN_600d37b8
//   60100b24 FUN_60100b24
//   60100c14 FUN_60100c14
//   600cb210 key_value_store__600cb210
//   600cbb14 FUN_600cbb14


/* src: key_value_store.cc */

undefined4
key_value_store__600cb460(undefined4 *param_1,int param_2,int param_3,uint param_4,byte param_5)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_r2;
  int iVar9;
  uint uVar10;
  byte local_cc [4];
  undefined1 auStack_c8 [2];
  ushort local_c6;
  ushort local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [134];
  
  uVar1 = *(ushort *)(param_1 + param_2 * 6 + 0x5b);
  if (uVar1 == param_4) {
    FUN_601018de(*param_1,auStack_c8,param_1[param_2 * 6 + 0x5a],8);
    bVar2 = FUN_600db002(param_1 + param_2 * 6 + 0x56,0x10);
    if ((bVar2 < 0x10) && ((local_c4 & 1) == (ushort)param_5)) {
      if (((local_c4 & 1) == 0) || (param_5 == 0)) {
        uVar3 = FUN_60100c14(param_1,param_1 + param_2 * 6 + 0x56,bVar2,param_3,(uint)uVar1);
        if (local_c6 != uVar3) {
          return 0;
        }
        iVar4 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8);
        iVar9 = param_1[param_2 * 6 + 0x5a];
        iVar5 = FUN_60100b24(extraout_r2,bVar2);
        for (uVar3 = 0; uVar3 < *(ushort *)(param_1 + param_2 * 6 + 0x5b); uVar3 = uVar3 + iVar8) {
          uVar10 = *(ushort *)(param_1 + param_2 * 6 + 0x5b) - uVar3;
          uVar6 = key_value_store__600cb210(param_1);
          if (uVar6 <= uVar10) {
            uVar10 = uVar6;
          }
          local_cc[0] = FUN_601018de(*param_1,(int)param_1 + 0xac9,uVar3 + iVar4 + iVar5 + iVar9,
                                     uVar10 & 0xffff);
          if (local_cc[0] != 0) {
            local_c0 = DAT_600cb590;
            local_bc = 0x1d4;
            local_b8 = local_aa;
            local_b4 = 0x80;
            uStack_b0 = 0;
            local_ac = 0;
            local_ab = 0;
            local_aa[0] = 0;
            FUN_600d37ac(&local_b8,DAT_600cb594);
            uVar7 = FUN_600cbb14(local_cc);
            FUN_60101b76(&local_b8,uVar7);
            FUN_600d37b8(&local_c0);
            return 0;
          }
          iVar8 = thunk_EXT_FUN_0000b554(param_3 + uVar3,(int)param_1 + 0xac9,uVar10);
          if (iVar8 != 0) {
            return 0;
          }
          iVar8 = key_value_store__600cb210(param_1);
        }
      }
      return 1;
    }
  }
  return 0;
}


