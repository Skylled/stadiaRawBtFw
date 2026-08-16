// 60081ab4  gatt_server__60081ab4  size=370 bytes
// src: gatt_server.cc
// --- callers ---
//   60081c6c FUN_60081c6c
// --- callees ---
//   6005d7c8 FUN_6005d7c8
//   600814b8 FUN_600814b8
//   600813cc FUN_600813cc
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6010165c FUN_6010165c
//   6005d9d0 gatt_server__6005d9d0
//   60066370 keys__60066370
//   600d4550 FUN_600d4550
//   60081a00 FUN_60081a00
//   600d4330 FUN_600d4330


/* src: gatt_server.cc */

void gatt_server__60081ab4(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 unaff_r8;
  uint local_34;
  undefined4 *local_30;
  uint local_2c;
  undefined4 local_28 [4];
  
  uVar4 = DAT_60081c30;
  iVar1 = DAT_60081c2c;
  *(undefined4 *)(DAT_60081c2c + 0x158) = DAT_60081c28;
  *(undefined4 *)(iVar1 + 0x134) = uVar4;
  *(int *)(iVar1 + 0x138) = iVar1 + 0x124;
  keys__60066370(0x3f,0x20,param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0xf0) = uVar4;
  *(undefined4 *)(iVar1 + 0x114) = uVar6;
  uVar6 = DAT_60081c34;
  *(int *)(iVar1 + 0xf4) = iVar1 + 0xe0;
  FUN_6005d7c8(&local_30,uVar6,0x10,DAT_60081c3c,DAT_60081c38);
  puVar7 = *(undefined4 **)(param_1 + 0x1c);
  if (local_30 == local_28) {
    if (puVar7 == (undefined4 *)(param_1 + 0x24)) {
      uVar5 = 0xf;
    }
    else {
      uVar5 = *(uint *)(param_1 + 0x24);
    }
    if (uVar5 < local_2c) {
      local_34 = local_2c;
      uVar6 = FUN_60081a00(&local_34);
      FUN_600d4550(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x1c) = uVar6;
      *(uint *)(param_1 + 0x24) = local_34;
    }
    if (local_2c != 0) {
      if (local_2c == 1) {
        **(undefined1 **)(param_1 + 0x1c) = *(undefined1 *)local_30;
      }
      else {
        thunk_EXT_FUN_0000b572(*(undefined1 **)(param_1 + 0x1c),local_30,local_2c);
      }
    }
    *(uint *)(param_1 + 0x20) = local_2c;
    *(undefined1 *)(*(int *)(param_1 + 0x1c) + local_2c) = 0;
  }
  else {
    if (puVar7 == (undefined4 *)(param_1 + 0x24)) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      unaff_r8 = *(undefined4 *)(param_1 + 0x24);
    }
    *(undefined4 *)(param_1 + 0x24) = local_28[0];
    *(undefined4 **)(param_1 + 0x1c) = local_30;
    *(uint *)(param_1 + 0x20) = local_2c;
    local_30 = local_28;
    if (puVar7 != (undefined4 *)0x0) {
      local_30 = puVar7;
      local_28[0] = unaff_r8;
    }
  }
  local_2c = 0;
  *(undefined1 *)local_30 = 0;
  FUN_600d4550(&local_30);
  iVar2 = DAT_60081c40;
  *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)(iVar1 + 0xb0) = iVar2;
  *(undefined4 *)(iVar1 + 0xac) = uVar4;
  uVar6 = DAT_60081c44;
  *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x68) = uVar4;
  *(int *)(iVar1 + 0x6c) = iVar2 + -0x44;
  *(undefined4 *)(iVar1 + 0x48) = DAT_60081c48;
  *(undefined4 *)(iVar1 + 0x4c) = 7;
  *(undefined4 *)(iVar1 + 0x24) = DAT_60081c4c;
  *(int *)(iVar1 + 0x28) = iVar2 + -0x88;
  cVar3 = gatt_server__6005d9d0(uVar6,iVar2 + -0x9c);
  iVar2 = DAT_60081c58;
  iVar1 = DAT_60081c54;
  if (cVar3 == '\0') {
    *(undefined4 *)(DAT_60081c54 + 0x24) = DAT_60081c50;
    *(int *)(iVar1 + 0x28) = param_1;
    if ((*(char *)(iVar2 + 0x4362) == '\0') ||
       (cVar3 = FUN_600d4330(DAT_60081c5c,0x1c,&local_30,200), cVar3 != '\0')) {
      FUN_6010165c(0x28,DAT_60081c64,0x7d,DAT_60081c60);
    }
    else {
      cVar3 = gatt_server__6005d9d0(DAT_60081c44,iVar1);
      if (cVar3 != '\0') {
        return;
      }
    }
    cVar3 = FUN_600813cc(DAT_60081c68);
    if (cVar3 == '\0') {
      uVar4 = FUN_600814b8(DAT_60081c68);
      gatt_server__6005d9d0(DAT_60081c44,uVar4);
    }
  }
  return;
}


