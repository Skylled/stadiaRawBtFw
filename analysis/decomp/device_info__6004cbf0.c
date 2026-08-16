// 6004cbf0  device_info__6004cbf0  size=320 bytes
// src: device_info.cc
// --- callers ---
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d1a8 thunk_EXT_FUN_00000eb8
//   6006615c keys__6006615c
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60059e94 FUN_60059e94
//   600d3b12 FUN_600d3b12
//   600d3b24 FUN_600d3b24
//   600df878 FUN_600df878
//   60081d38 FUN_60081d38
//   6005a464 dynamic_buffer__6005a464
//   6005a01c FUN_6005a01c
//   600d3b3a FUN_600d3b3a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60051120 FUN_60051120
//   600df810 FUN_600df810


/* src: device_info.cc */

undefined1 device_info__6004cbf0(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  bool bVar8;
  int local_110;
  uint local_10c;
  uint local_108;
  int iStack_104;
  undefined1 auStack_f4 [20];
  undefined1 auStack_e0 [4];
  undefined4 local_dc;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_28;
  
  uVar5 = *(uint *)(param_1 + 0xa0);
  iVar6 = *(int *)(param_1 + 0xa4);
  if ((uVar5 == 0 && iVar6 == 0) ||
     ((int)((DAT_6004cd54 - iVar6) - (uint)(DAT_6004cd50 < uVar5)) < 0 !=
      (SBORROW4(DAT_6004cd54,iVar6) != SBORROW4(DAT_6004cd54 - iVar6,(uint)(DAT_6004cd50 < uVar5))))
     ) {
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    local_c0 = DAT_6004cd30;
    local_bc = 0xf0;
    FUN_600d3b3a(&local_b8);
    FUN_600d37ac(&local_b8,DAT_6004cd34);
    FUN_600d3b24(&local_c0);
    cVar1 = FUN_60059e94(&local_c0,8);
    if (cVar1 != '\0') {
      return 2;
    }
    *(undefined4 *)(param_1 + 0x98) = local_c0;
    *(undefined4 *)(param_1 + 0x9c) = local_bc;
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  thunk_EXT_FUN_00000eb8(1,&local_108);
  bVar8 = CARRY4(local_108,DAT_6004cd38);
  iVar6 = local_108 + DAT_6004cd38;
  local_110 = thunk_EXT_FUN_0000b532(0x20);
  puVar2 = (undefined1 *)thunk_EXT_FUN_0000b5ba(local_110,0,0x18);
  *puVar2 = 1;
  puVar2[0x10] = 1;
  uVar3 = *(undefined4 *)(param_1 + 0x98);
  uVar4 = *(undefined4 *)(param_1 + 0x9c);
  *(int *)(puVar2 + 0x18) = iVar6;
  *(uint *)(puVar2 + 0x1c) = iStack_104 + (uint)bVar8;
  *(undefined4 *)(puVar2 + 8) = uVar3;
  *(undefined4 *)(puVar2 + 0xc) = uVar4;
  local_10c = 0;
  iVar6 = FUN_600df878(&local_10c,DAT_6004cd3c,puVar2);
  if ((iVar6 == 0) || (0x80 < local_10c)) {
    uVar7 = 0xd;
  }
  else {
    local_c0 = DAT_6004cd40;
    local_b4 = DAT_6004cd44;
    local_b8 = DAT_6004cd48;
    dynamic_buffer__6005a464(auStack_e0,local_10c,&local_c0);
    FUN_60081d38(auStack_f4,local_dc,local_10c);
    iVar6 = FUN_600df810(auStack_f4,DAT_6004cd3c,local_110);
    if (iVar6 == 0) {
      uVar7 = 0xd;
    }
    else {
      uVar5 = keys__6006615c(4,local_dc,local_10c & 0xffff);
      if ((uVar5 & 0xff) == 0) {
        uVar3 = *(undefined4 *)(local_110 + 0x1c);
        *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(local_110 + 0x18);
        *(undefined4 *)(param_1 + 0xa4) = uVar3;
        uVar7 = 0;
      }
      else {
        FUN_60051120(&local_c0,DAT_6004cd30,0x118,uVar5);
        FUN_600d37ac(&local_b8,DAT_6004cd4c);
        FUN_600d37b8(&local_c0);
        uVar7 = local_28;
      }
    }
    FUN_6005a01c(auStack_e0);
  }
  FUN_600d3b12(&local_110);
  return uVar7;
}


