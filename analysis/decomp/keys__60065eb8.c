// 60065eb8  keys__60065eb8  size=400 bytes
// src: keys.cc
// --- callers ---
//   60065a74 ble_info__60065a74
//   600668dc keys__600668dc
//   6005a05c device_info__6005a05c
//   60080fb8 FUN_60080fb8
//   60077140 FUN_60077140
//   60078b4c get_device_data__60078b4c
//   600666f0 keys__600666f0
//   6005ded8 FUN_6005ded8
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   600d6db8 FUN_600d6db8
//   600cb598 key_value_store__600cb598
//   60101b76 FUN_60101b76
//   600d37b8 FUN_600d37b8
//   600d6e14 FUN_600d6e14
//   600d37ac FUN_600d37ac
//   601010c8 FUN_601010c8
//   600cbb14 FUN_600cbb14
//   60065ccc FUN_60065ccc
//   60065db0 FUN_60065db0
//   60051120 FUN_60051120
//   601024d8 FUN_601024d8
//   600d6d96 FUN_600d6d96


/* src: keys.cc */

char keys__60065eb8(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  byte local_c0 [2];
  ushort local_be;
  undefined4 local_bc;
  undefined4 local_b8;
  byte *pbStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  byte local_a8;
  byte local_a7;
  byte local_a6 [130];
  char local_24;
  
  iVar4 = FUN_60065ccc();
  if (iVar4 == DAT_60066048) {
    FUN_60051120(&local_bc,DAT_6006604c,0x2b0,3);
    uVar6 = DAT_60066050;
  }
  else {
    bVar1 = *(byte *)(iVar4 + 0xc);
    uVar7 = (uint)bVar1;
    if (uVar7 == 0) {
      iVar5 = FUN_600d6e14(param_1);
      if (iVar5 == 0) {
        if (*(char *)(iVar4 + 0x18) == '\0') {
          return '\x05';
        }
        iVar5 = 0;
        while( true ) {
          if (param_3 == iVar5) {
            return '\x0f';
          }
          if (*(char *)(*(int *)(iVar4 + 0x10) + iVar5) == '\0') break;
          iVar5 = iVar5 + 1;
        }
        FUN_601024d8(param_2,*(int *)(iVar4 + 0x10),param_3);
        return '\0';
      }
      uVar6 = FUN_60065db0(param_1);
      uVar8 = *(undefined4 *)(iVar4 + 8);
      local_be = (ushort)bVar1;
      cVar2 = FUN_601010c8(uVar6,uVar8,&local_be);
      if (cVar2 != '\0') {
        return cVar2;
      }
      if ((int)(uint)local_be < param_3) {
        bVar3 = key_value_store__600cb598(uVar6,uVar8,param_2,(uint)local_be,0);
        if (bVar3 == 0) {
          *(undefined1 *)(param_2 + (uint)local_be) = 0;
          return '\0';
        }
        pbStack_b4 = local_a6;
        local_bc = DAT_6006604c;
        uStack_ac = uVar7;
        local_a8 = bVar1;
        local_a7 = bVar1;
        local_a6[0] = bVar1;
        if (bVar3 == 0xf) {
          local_b8 = 0x1cc;
          local_b0 = 0x80;
          FUN_600d37ac(&pbStack_b4,DAT_60066064);
          FUN_600d37ac(&pbStack_b4,uVar8);
          FUN_600d37ac(&pbStack_b4,DAT_60066068);
        }
        else {
          local_b8 = 0x1ce;
          local_b0 = 0x80;
          FUN_600d37ac(&pbStack_b4,DAT_6006606c);
          local_c0[0] = bVar3;
          uVar6 = FUN_600cbb14(local_c0);
          FUN_60101b76(&pbStack_b4,uVar6);
        }
        FUN_600d37b8(&local_bc);
        return bVar3;
      }
      FUN_60051120(&local_bc,DAT_6006604c,0x1c4,8);
      FUN_600d37ac(&pbStack_b4,DAT_60066058);
      FUN_600d37ac(&pbStack_b4,uVar8);
      FUN_600d37ac(&pbStack_b4,DAT_6006605c);
      FUN_600d6db8(&pbStack_b4,local_be);
      FUN_600d37ac(&pbStack_b4,DAT_60066060);
      FUN_600d6d96(&pbStack_b4,param_3);
      goto LAB_60065ee8;
    }
    FUN_60051120(&local_bc,DAT_6006604c,0x2b1,3);
    FUN_600d37ac(&pbStack_b4,*(undefined4 *)(iVar4 + 8));
    uVar6 = DAT_60066054;
  }
  FUN_600d37ac(&pbStack_b4,uVar6);
LAB_60065ee8:
  FUN_600d37b8(&local_bc);
  return local_24;
}


