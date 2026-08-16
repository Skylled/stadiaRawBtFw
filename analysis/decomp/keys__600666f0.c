// 600666f0  keys__600666f0  size=604 bytes
// src: keys.cc
// --- callers ---
//   600d736c FUN_600d736c
// --- callees ---
//   60101b76 FUN_60101b76
//   600d7032 FUN_600d7032
//   60065e68 keys__60065e68
//   600d37b8 FUN_600d37b8
//   60065eb8 keys__60065eb8
//   60101ba2 FUN_60101ba2
//   600d37ac FUN_600d37ac
//   600d72b8 FUN_600d72b8
//   60065ccc FUN_60065ccc
//   60101c5c thunk_EXT_FUN_0000b52a
//   600d39ba FUN_600d39ba
//   600d6d96 FUN_600d6d96
//   600d708c FUN_600d708c
//   60065df0 keys__60065df0
//   600d6db8 FUN_600d6db8
//   600d6f24 FUN_600d6f24
//   60050c18 FUN_60050c18
//   600d6eca FUN_600d6eca
//   6013d038 thunk_EXT_FUN_00008832
//   60051120 FUN_60051120
//   600d6fd8 FUN_600d6fd8
//   600d70e6 FUN_600d70e6
//   600d382e FUN_600d382e
//   600d6f7e FUN_600d6f7e
//   60101b0c FUN_60101b0c
//   600d732e FUN_600d732e


/* WARNING: Removing unreachable block (ram,0x6006653c) */
/* WARNING: Removing unreachable block (ram,0x60066544) */
/* src: keys.cc */

uint keys__600666f0(undefined4 param_1,int *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ushort local_ba;
  uint local_b8;
  int iStack_b4;
  undefined1 auStack_b0 [144];
  byte local_20;
  
  uVar5 = keys__60065e68();
  if (((uVar5 & 0xff) != 0) || (uVar5 = FUN_60101b76(param_2,DAT_6006671c), (uVar5 & 0xff) != 0)) {
    return uVar5;
  }
  iVar3 = FUN_60065ccc();
  if (iVar3 == DAT_600666d8) {
    FUN_60051120(&local_b8,DAT_600666dc,0x333,3);
    FUN_600d37ac(auStack_b0,DAT_600666e0);
    FUN_600d37b8(&local_b8);
    return (uint)local_20;
  }
  uVar4 = DAT_600666e4;
  if ((*(char *)(iVar3 + 0xd) == '\x01') ||
     (cVar1 = keys__60065df0(param_1,&local_ba), uVar4 = DAT_600666e8, cVar1 != '\0')) {
    uVar5 = FUN_60101b76(param_2,uVar4);
    return uVar5;
  }
  if ((param_2[1] + -1) - param_2[2] <= (int)(uint)local_ba) {
LAB_60066510:
    FUN_60101b76(param_2,DAT_600666ec);
    return 0xf;
  }
  if (*(char *)(iVar3 + 0xc) == '\0') {
    uVar5 = local_ba + 1 & 0xffff;
    iVar3 = thunk_EXT_FUN_00008832(uVar5);
    if (iVar3 != 0) {
      uVar5 = keys__60065eb8(param_1,iVar3,uVar5);
      if ((uVar5 & 0xff) == 0) {
        uVar5 = FUN_60101b76(param_2,iVar3);
      }
      if (iVar3 == 0) {
        return uVar5;
      }
      thunk_EXT_FUN_0000b52a(iVar3);
      return uVar5;
    }
    goto LAB_60066510;
  }
  switch(*(char *)(iVar3 + 0xc)) {
  case '\x01':
    uVar5 = FUN_600d732e(param_1,param_2);
    return uVar5;
  case '\x02':
    bVar2 = FUN_600d7032(param_1,&local_b8);
    goto LAB_600665b4;
  case '\x03':
    bVar2 = FUN_600d72b8(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    iVar3 = FUN_600d6d96(param_2,local_b8);
    goto LAB_600665a8;
  case '\x04':
    bVar2 = FUN_600d70e6(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    goto LAB_600665f4;
  case '\x05':
    bVar2 = FUN_600d382e(param_1,&local_b8);
LAB_600665b4:
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    uVar4 = FUN_60050c18(local_b8,0,param_2[2] + *param_2,param_2[1] - param_2[2]);
    FUN_60101ba2(param_2,uVar4);
    return (uint)*(byte *)(param_2 + 3);
  case '\x06':
    bVar2 = FUN_600d708c(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    iVar3 = FUN_600d6db8(param_2,local_b8 & 0xffff);
LAB_600665a8:
    return (uint)*(byte *)(iVar3 + 0xc);
  case '\a':
    bVar2 = FUN_600d39ba(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    local_b8 = local_b8 & 0xff;
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    iStack_b4 = 0;
LAB_600665f4:
    uVar4 = FUN_60050c18(local_b8,iStack_b4,iVar3,iVar6);
    goto LAB_600665f8;
  case '\b':
    bVar2 = FUN_600d6fd8(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    goto LAB_6006666a;
  case '\t':
    bVar2 = FUN_600d6f7e(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    break;
  case '\n':
    bVar2 = FUN_600d6f24(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    local_b8 = (uint)(short)local_b8;
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    break;
  case '\v':
    bVar2 = FUN_600d6eca(param_1,&local_b8);
    if (bVar2 != 0) {
      return (uint)bVar2;
    }
    local_b8 = (uint)(char)local_b8;
    iVar6 = param_2[1] - param_2[2];
    iVar3 = param_2[2] + *param_2;
    break;
  default:
    return 0xd;
  }
  iStack_b4 = (int)local_b8 >> 0x1f;
LAB_6006666a:
  uVar4 = FUN_60101b0c(local_b8,iStack_b4,iVar3,iVar6);
LAB_600665f8:
  FUN_60101ba2(param_2,uVar4);
  return (uint)*(byte *)(param_2 + 3);
}


